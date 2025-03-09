#include <iostream>

class Logger {
public:
    static Logger& instance() {
        static Logger instance; // Создание единственного экземпляра
        return instance;
    }

    Logger(const Logger&) = delete; // Запрет копирования
    Logger& operator=(const Logger&) = delete; // Запрет присваивания

    Logger& log(int value) {
        std::cout << value;
        return *this;
    }

    Logger& log(const char* message) {
        std::cout << message;
        return *this;
    }

    Logger& log(char character) {
        std::cout << character;
        return *this;
    }

private:
    Logger() {
        std::cout << "Logger is created\n";
    }

    ~Logger() {
        std::cout << "Logger is destroyed\n";
    }
};

class IntCharPair {
public:
    IntCharPair(int n, char c) : n(n), c(c) {}

    // Доступ к полям класса IntCharPair
    int getN() const { return n; }
    char getC() const { return c; }

private:
    int n;
    char c;
};

Logger& log(Logger& logger, const IntCharPair& pair) {
    return logger.log('(').log(pair.getN()).log(", ").log(pair.getC()).log(')');
}

int main() {
    IntCharPair pair(10, 'x');
    log(Logger::instance(), pair).log('\n');

    return 0;
}
