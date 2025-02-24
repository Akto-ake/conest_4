#include <iostream>

// Описать класс B таким образом, чтобы все конструкции функции main были верными, а на экран выдалось 10 20 30.
 
class B{
    private:
        int a;
    public:
        B(){
            a = 10;
        }

        int get(){
            return a;
        }

        B(B & b){
            a = b.a + 10;
        }
};

int main() {
    B b1, b2 = b1, b3(b2);
    std::cout << b1.get() << ' ' << b2.get() << ' ' << b3.get() << std::endl;
    return 0;
}
