#include <iostream>

// Реализуйте класс Logger для печати отладочной информации на стандартный поток вывода.
//  Определите в классе методы log(int), log(const char*) и метод log(char). Причем должна быть возможность вызвать их цепочкой: .log("x = ").log(x).log('\n').

// Класс Logger соответствует шаблону проектирования Singleton(одиночка), то есть во время работы программы может существовать не более одного объекта этого класса. 
// Он возвращается статическим методом instance() этого класса. Если instance() не использовался, объект Logger не должен создаваться (и удаляться). 
// У класса Logger нет полей с данными.

// Добавьте в конструктор класса Logger печать строки "Logger is created\n", а в деструктор "Logger is destroyed\n".

// Есть класс:


// class IntCharPair {
// public:
//     IntCharPair(int, char);
//     // not more than one new declaration is allowed here
// private:
//     int n;
//     char c;
// };

        
// Реализуйте (внешнюю) функцию log(Logger&, const IntCharPair&) для печати IntCharPair(n, c) как (n, c).
//  Разрешите этой функции обратиться к полям класса IntCharPair. Должен работать такой код:


//     IntCharPair pair(10, 'x');
//     log(Logger::instance(), pair).log('\n');

        
// Исходный код класса IntCharPair поместите в свою программу.

// Ответьте на вопросы:

// Чему равен sizeof(Logger)? Чему равен размер объектов пустого класса?
// Как сделать, чтобы в разных программах можно было сделать печать в разные файлы, если полей в классе нет?

class Logger {

public:
    static Logger& instance() {
        static Logger obj;
        return obj;
    }

    //log int
    //log const char*
    //log char

    Logger& log(int a) {
        std::cout << a;
        return *this;
    }

    Logger& log(const char* a) {
        std::cout << a;
        return *this;
    }

    Logger& log(char a) {
        std::cout << a;
        return *this;
    }
private:
    Logger() {
        std::cout << "Logger is created\n";
    }   

    ~Logger() {
        std::cout << "Logger is destroyed\n";
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

};

class IntCharPair {
private:
    int n;
    char c;
public:
    IntCharPair(int n_new, char c_new){
        n = n_new;
        c = c_new;
    };

    friend Logger& log(Logger&, const IntCharPair&);

};


//(n,c)
Logger& log(Logger& logger, const IntCharPair& pair) {
    int first = pair.n;
    char second = pair.c;
    return logger.log('(').log(first).log(", ").log(second).log(')');
}

//Чему равен sizeof(Logger)? Чему равен размер объектов пустого класса?
//sizeof(Logger) равен 1 байт. 
//Размер объектов пустого класса фактически должен быть нулевым, но так как каждому объекту присуждается свой адрес, то они также имеют размер 1 байт

// Как сделать, чтобы в разных программах можно было сделать печать в разные файлы, если полей в классе нет?
// можно изменить указатель потока вывода


// int main(){
//     IntCharPair pair(10, 'x');
//     log(Logger::instance(), pair).log('\n');
// }
