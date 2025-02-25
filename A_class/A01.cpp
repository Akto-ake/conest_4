#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <new>

class A {
private:
    int a;

public:
    A(){
        a = 0;
        std::cout << "1 ";
    }

    A(const A & b){
        a = b.a;

        std::cout << "2 ";
    }

    A(double b) {
        a = static_cast<int>(b);
        std::cout << "3 ";
    }

    A(float b, unsigned short c) {
        a = static_cast<int>(b);
        std::cout << "4 ";
    }

    ~A() {
        std::cout << "5 ";
    }
//1 5 3 2 5 5 2 4 5 5.
    // void m() {
    //     A * p = new A(); //1
    //     delete p; //5

    //     A * p1 = new A(1.2); //3
    //     A p2 = *p1;

    //     p1->~A(); //5

    //     A a3(p2);
    //     A a4(1.5, 2); 
    // }

    void m() {
        { 
            A * p5 = new A(); 
            delete p5;
        }

        {
            A a2(1.2);
            A a3(a2);
        }

        {
            A p(*this);
            A p1(1.5, 2);
        }
    }
};

