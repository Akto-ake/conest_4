#include <iostream>

// Описать класс C и операцию + таким образом, чтобы все конструкции функции main были верными, а на экран выдалось 14 10 48.

// Симметричные операции следует описывать вне класса.

class C{
    private:
        int a;
    public:
        C(int x){
            a = x * 2;
        }  

        C operator+(C const & x) {
            return C(a + x.a);
        }

        // friend C operator+(C const & x, C const & y) {
        //     return C(x.a + x.a);
        // }

        int get(){
            return a;
        }
};

int main() {
    C c1(7), c2 = 5, c3(c1 + c2);
    std::cout << c1.get() << ' ' << c2.get() << ' ' << c3.get() << std::endl;
    return 0;
}
