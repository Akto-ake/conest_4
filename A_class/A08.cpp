#include <iostream>

// Опишите класс А, чтобы были верными все следующие конструкции:

class A{
    public:
        static int x;
        static int get(){
            return x;
        }

        void f(){
            x ++;
        }
};

int A::x = 0;

int main() {
    A a;
    a.f();
    a.f();
    a.f();
    std::cout << A::get() << std::endl; // 3
    a.f();
    std::cout << A::get() << std::endl; // 4
}
