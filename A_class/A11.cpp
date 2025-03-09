#include <iostream>
#include <cstdlib>

class DynArray{
private:
    int size = 0;
    int capacity = 1;
    int *mass;
public:
    DynArray(int s = 0, int c = 1) : size(s), capacity(c){
        mass = new int[capacity];
        for (int j = 0; j < capacity; j++){
            mass[j] = 0;
        }
    }

    DynArray(const DynArray& mass2): DynArray(mass2.size, mass2.capacity){
        int i = 0;
        for(i = 0; i < size; i++){
            mass[i] = mass2.mass[i];
        }

    }

    ~DynArray(){
        delete [] mass;
        size = 0;
        capacity = 0;
    }

    int length() const{
        return size;
    }

    const int& operator[](int i) const{

        if ((i < 0) || (i >= size)){
            std::cout << "Out of bounds\n";
            exit(0);
        }

        return mass[i];
    }



    int& operator[](int i){

        if (i < 0){
            std::cout << "Out of bounds\n";
            exit(0);
        }

        if (i >= size){
            if (i < capacity){
                size = i+1;
            }
            else{
                while(i >= capacity){
                    if (capacity == 0)
                        capacity = 1;
                    else
                        capacity *= 2;
                }


                int * new_mass = new int[capacity];

                for (int j = 0; j < capacity; j++){
                    new_mass[j] = 0;
                }

                for (int j = 0; j < size; j++){
                    new_mass[j] = mass[j];
                }

                delete[] mass;
                mass = new_mass;
                size = i + 1;

            };
        }

        return mass[i];
    }

    friend std::ostream& operator<<(std::ostream& out, const DynArray& o){
        for (int i = 0; i<o.size; i++){
            out << o.mass[i];
            if (i + 1 < o.size){
                out << " ";
            }
        }
        return out;
    }
};


// Реализуйте динамически расширяемый массив элементов типа int. Массив отводится в динамической памяти.

// По умолчанию массив не занимает места в динамической памяти. 
// Массив расширяется при попытке записать/прочитать значение на позиции за пределами массива. 
// Однако если объект константный и позиция находится за пределами, надо напечатать на экран строку 
// "Out of bounds\n" и завершить процесс (exit(0);). 
//   Необходимо перегрузить операцию(и) индексирования [] для чтения или изменения (если объект неконстантный)
//   элементов массива. При расширении все элементы массива инициализируются нулями. Избегайте дублирования кода!

// Нужно определиь метод length(), который возвращает текущий размер массива. 
//   Необходимо хранить два внутренних поля: size(текущий размер массива) и capacity(размер отведённой памяти). 
//   Размер отведённой памяти должен быть равен степени двойки и увеличиваться сразу в 2N раз при необходимости.

// Перегрузите операцию << для печати элементов массива на стандартный поток вывода последовательно через пробел
//   в одну строку. В конце пробела нет.

// Отправлять на проверку надо только описание класса, методов и функций. Реализация будет тестироваться во
//   т с такой функцией main():


// #include <iostream>

// int main()
// {
//     DynArray a;

//     int n, i = 0;
//     while(std::cin >> n) {
//         a[i++] = n;
//     }

//     std::cout << a.length() << std::endl;

//     const DynArray b(a);
//     std::cout << b << std::endl;
//     std::cout << b[4] << std::endl;

//     DynArray c;
//     c[200] = 200;
//     std::cout << c[3] << ' ' << c[199] << ' ' << c[200] << std::endl;

//     DynArray d = c;
//     std::cout << d.length() << std::endl;

//     DynArray a1;
//     a1[0] = 0; a1[1] = 1; a1[2] = 2;
//     std::cout << a1 << std::endl;
// }
