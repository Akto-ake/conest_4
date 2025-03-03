#include <cstring>
#include <iostream>
#include <utility>

// Рассмотрим концепцию "умные указатели" (smart pointers). Основная задача умных указателей — гарантировать освобождение памяти, 
// когда указатель больше не используется. Рассмотрим пример, в котором при выходе из функции f возникнет утечка памяти:


//           void f() {
//             char* str = new char[15]; // memory leak
//           }
        
// Используя вместо char* специальный класс с деструктором, освобождающим память, можно избежать утечки.

//           void f() {
//             CharPtr str = new char[15];
//           }
//           // destructor is called, no memory leak
        
// Реализуйте класс UniqueCharPtr — умный указатель на char без разделения доступа. Умный указатель может быть в двух состояниях: 
// либо он "владеет" некоторой областью памяти (знает адрес), либо у него нет адреса ("пустой"). 
// Владение означает, что никакой другой объект не имеет адрес этой же области памяти. И при удалении умного указателя удаляется и область памяти, если она есть.

// Создание: по умолчанию создаётся пустой указатель. Также надо определить конструктор, который получает указатель на отведённую область памяти (char*). 
// Нельзя использовать строковые константы (const char*) для инициализации.

// Поскольку надо реализовать уникальный умный указатель, который может принадлежать только одному объекту, копирование указателей должно быть запрещено.
//  Вместо этого надо реализовать семантику переноса.

// Умный указатель можно использовать везде, где требуется char*.
//  Для этого надо добавить метод неявного преобразования типа UniqueCharPtr к типу char*.

// Следующая функция main должна корректно работать:

class UniqueCharPtr{
    private:
        char* SmartPtr;
    public:
        UniqueCharPtr(){
            SmartPtr = nullptr;
        }

        UniqueCharPtr(char* a){
            SmartPtr = a;
        }
    
        UniqueCharPtr(const UniqueCharPtr&) = delete; //запрет

        UniqueCharPtr(UniqueCharPtr&& a){ //перенос
            SmartPtr = a.SmartPtr;
            a.SmartPtr = nullptr;
        }
    
        UniqueCharPtr& operator=(UniqueCharPtr&& a) {
            delete[] SmartPtr;
            SmartPtr = a.SmartPtr;
            a.SmartPtr = nullptr;
            return *this;
        }
    
        operator char*() {
            return SmartPtr;
        }

        ~UniqueCharPtr() {
            delete[] SmartPtr;
        }
    };


int main() {
    UniqueCharPtr p1 = new char[15];
    strcpy(p1, "Smart pointers");

    // UniqueCharPtr p2 = p1; // Not allowed!
    UniqueCharPtr p2 = std::move(p1);
    std::cout << p2 << std::endl;
    std::cout << *p2 << *(p2+1) << std::endl;

    UniqueCharPtr p3;
    // p3 = "Smart pointers"; // Not allowed!
    // p3 = p2; // Not allowed!
    p3 = new char[15];
    p3 = new char[20];
    strcpy(p3, p2);
    std::cout << p3 << std::endl;

    UniqueCharPtr p4;
}
