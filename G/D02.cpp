#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

enum State {S, ERROR, A, B};

class DKA{
    int k;
    int flag_0;
    char c;
public:

    bool accept(std::string& str){
        State state = S;
        k = 0;
        flag_0 = 1;
        std::istringstream input(str);
        while(state != ERROR && input >> c){
            switch (state){
            case S:
                if (std::isalpha(c))
                    state = A;
                else if (std::isdigit(c)){
                    if (c == '0')
                        flag_0 = 0;
                    state = C;
                }
                else state = ERROR;
                break;
            case A:
                if (std::isdigit(c) && (flag_0)){
                    state = B;
                }
                else if (std::isalpha(c) || (c == '_')){
                    state = A;
                }
                else state = ERROR;
                break;

            case B:
                if (std::isdigit(c)){
                    state = B;
                }
                else if ((std::isalpha(c) || (c == '_'))){
                    k = 0;
                    state = A;
                }
                else if ((c == '.') && (k == 0)){
                    k=1;
                    input >> c;
                    if (std::isdigit(c))
                        state = B;
                    else
                        state = ERROR;
                }
                else state = ERROR;
                break;

            case C:
                if (std::isdigit(c) && flag_0){
                    state = C;
                }
                else if ((c == '.') && (k == 0)){
                    k=1;
                    input >> c;
                    if (std::isdigit(c))
                        state = C;
                    else
                        state = ERROR;
                }
                else state = ERROR;
                break;
            default:
                state = ERROR;
            }
        }

        if ((state == ERROR))
            return false;
        return true;
    }
};


int main() {
    DKA g;

    std::string str;
    while (std::cin >> str) {
        if (g.accept(str))
            std::cout << "OK: ";
        else
            std::cout << "ERROR: ";
        std::cout << str << std::endl;
    }
}
