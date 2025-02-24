#include <iostream>

// Описать класс А так, чтобы:

// все конструкции функции main были верными
// явно в классе А было описано не более одного конструктора
// на экран выдалось 15 60 7

class A{
    private:
        int a;
    public:
        A(int x = 7){
            a = x;
        }  

        A operator*=(A const & x) {
            a *= x.a;
            return *this;
        }

        // friend C operator+(C const & x, C const & y) {
        //     return C(x.a + x.a);
        // }

        int get(){
            return a;
        }
};

int main() {
    A a1(5), a2 = 4, a3;
    a2 *= a1 *= 3;
    std::cout << a1.get() << ' ' << a2.get() << ' ' << a3.get() << std::endl;
    return 0;
}
