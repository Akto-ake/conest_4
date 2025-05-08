#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

enum TokenType {
    END = 0,
    IDENT = 1,
    INTEGER = 2,
    FLOAT = 3,
    OP_1 = 4, // * and /
    OP_2 = 5, // + and -
    OP_3 = 6, // =
    OP_plus = 7, // ++
    OP_min = 8, // --
    SEP_open = 9,
    SEP_close = 10,
    SEP_end = 11,
    ERROR = 255
};

class Token {
    TokenType type;
    std::string val;

public:
    Token(){
        type = END;
        val = "";
    }

    Token(TokenType type_2, const std::string& val_2) : type(type_2), val(val_2) {}

    TokenType getKind() const {
        return type;
    }

    const std::string& getValue() const {
        return val;
    }

    operator bool() const {
        return type != END && type != ERROR;
    }
};

enum State {S, ERR, ALPHA, ID, INTEG, OPERATOR, DOT};

class Scanner{
    std::istream& input;
    int flag_0;
public:
    Scanner(std::istream& in = std::cin) : input(in){}

    Token getToken();
};

Token Scanner::getToken(){
    State state = S;
    std::string str;
    char ch;
    int flag_dot = 0;

    while (state != ERR && input.get(ch)) {
        if (std::isspace(ch)){
            continue;
        }
        // if (ch == '/'){
        //     input.get(ch);
        //     if (ch == '/') {
        //         while (input.get(ch) && ch != '\n');
        //         return Token(END, str);
        //     }
        //     input.unget();
        //     ch = '/';
        // }
        str += ch;
        switch(state){
        case S:
            if (ch == '('){
                return Token(SEP_open, str);
            }
            if (ch == ')'){
                return Token(SEP_close, str);
            }
            if (ch == ';') {
                return Token(SEP_end, str);
            }
            if ((ch == '*') || (ch == '/')) {
                return Token(OP_1, str);
            }
            if (ch == '=') {
                return Token(OP_3, str);
            }
            if ((ch == '+') || (ch == '-')) {
                state = OPERATOR;
            } else if (std::isalpha(ch)) {
                state = ID;
            } else if (std::isdigit(ch)){
                if (ch == '0')
                    flag_0 = 0;
                state = INTEG;
            } else {
                state = ERR;
            }
            break;
        case ID:
            if (std::isalnum(ch) || (ch == '_')) {
                state = ID;
            } else {
                input.unget();
                str.pop_back();
                return Token(IDENT, str);
            }
            break;
        case INTEG:
            if (std::isdigit(ch)) {
                state = INTEG;
            } else if (ch == '.') {
                state = DOT;
            } else {
                input.unget();
                str.pop_back();
                return Token(INTEGER, str);
            }
            break;
        case DOT:
            if (std::isdigit(ch)) {
                flag_dot = 1;
                state = DOT;
            } else {
                if (!flag_dot){
                    state = ERR;
                }else{
                    input.unget();
                    str.pop_back();
                    return Token(FLOAT, str);
                }
            }
            break;
        case OPERATOR:
            if (ch == '+' && *(str.end() - 2) == '+') {
                return Token(OP_plus, "++");
            } else if (ch == '-' && *(str.end() - 2) == '-'){
                return Token(OP_min, "--");
            } else {
                input.unget();
                str.pop_back();
                return Token(OP_2, str);
            }
            break;
        default:
            state = ERR;
        }
    }
    if (str.empty() && input.eof()) {
        return Token(END, "");
    }
    return Token(ERROR, str);
}

class Parser{
    std::istringstream input_pars;
    Scanner scanner;
    Token tok;
    void gt(){ tok = scanner.getToken(); }

public:
    Parser(const std::string& in) : input_pars(in), scanner(input_pars){}

    bool parse();

    void S();
    void S_1();
    void A();
    void M();
    void T();
    void Q();
    void R();
};

bool Parser::parse(){
    try{
        gt(); 
        S();
        return (tok.getKind() == END);
    }
    catch(const Token& t){return false;}
}

// S -> ; | S1 ;
void Parser::S(){
    if (tok.getKind() == SEP_end){gt(); }
    else{
        // gt();
        S_1();
        if (tok.getKind() == SEP_end){gt(); }
        else throw tok;
    }
}

// S1 -> A { = A }
void Parser::S_1(){
    A();
    while(tok.getKind() == OP_3){
        gt();
        A();
    }
}

// A -> M { + M | - M }
void Parser::A(){
    M();
    while(tok.getKind() == OP_2){
        gt();
        M();
    }
}

// M -> T { * T | / T }
void Parser::M(){
    T();
    while(tok.getKind() == OP_1){
        gt();
        T();
    }
}

// T -> { ++ | -- | -} Q
void Parser::T(){
    while ((tok.getKind() == OP_plus) || (tok.getKind() == OP_min) || (tok.getKind() == OP_2)){
        gt();
    }
    Q();
}

// Q -> ident R | integer R | float R | ( S1 ) R 
void Parser::Q(){
    if (tok.getKind() == IDENT){ 
        gt(); 
        R();
    }
    else if (tok.getKind() == INTEGER){
        gt();
        R();
    }
    else if (tok.getKind() == FLOAT){
        gt();
        R();
    }
    else if (tok.getKind() == SEP_open){
            gt();
            S_1();
            if (tok.getKind() == SEP_close){
                gt();
                R();
            } else{
                throw tok;
            }
    }
    else throw tok;
}

// R -> { ++ | -- }
void Parser::R(){
    while ((tok.getKind() == OP_plus) || (tok.getKind() == OP_min)){
        gt();
    }
}

int main() {
    std::string str;

    while ( std::getline(std::cin, str) ) {
        Parser parser(str);
        if (parser.parse())
            std::cout << "OK: ";
        else
            std::cout << "ERROR: ";
        std::cout << str << std::endl;
    }
}