#include <iostream>
#include <string>
#include <sstream>
#include <cctype>


// Воспользуйтесь решением из предыдущего задания, выполняющим анализ цепочек регулярного языка, заданного регулярным выражением: aba*b*

// Но теперь надо допускать только те цепочки, которые содержат равное количество a и b. 
// То есть анализатор должен принимать цепочки вот такого языка: { abanbn | n >= 0 }

// Такой язык не является регулярным, это КС язык, однако мы можем расширить класс языков, принимаемых конечным автоматом
// , добавив в переходы дополнительные действия. 
// Добавьте в реализацию счётчики и принимайте только цепочки с равным количеством a и b.
enum State {S, ERROR, B, C};

class DKA{
    char c;
    int k_a;
    int k_b;
public:

    bool accept(std::string& str){
        State state = S;
        k_a = 1;
        k_b = 1;
        std::istringstream input(str);
        while(state != ERROR && input >> c){
            switch (state){
            case S:
                if (c == 'a'){
                    input >> c;
                    if (c == 'b')
                        state = B;
                    else state = ERROR;
                }
                else state = ERROR;
                break;

            case B:
                if ((c == 'a')){
                    k_a ++;
                    state = B;
                }
                else if ((c == 'b')){
                    k_b ++;
                    state = C;
                }
                else state = ERROR;
                break;
            case C:
                if (c == 'b'){
                    k_b++;
                    state = C;
                }
                else state = ERROR;
                break;
            default:
                state = ERROR;
            }
        }
        if ((state == ERROR) || (k_a != k_b))
            return false;
        return true;
    }
};


#include <iostream>
#include <string>

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


