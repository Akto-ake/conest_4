#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
#include <cstdlib>
#include <new>
#include <cstdio>

// Продолжаем реализовывать "умные указатели" (smart pointers). Основная задача умных указателей — гарантировать освобождение памяти, 
// когда указатель больше не используется.

// Реализуйте класс SharedPtr — умный указатель с разделением доступа, аналог библиотечных умных указателей std::shared_ptr

// Разделение доступа означает, что несколько объектов типа SharedPtr могут указывать на один и тот же объект в динамической памяти.
//  Динамическая память освобождается, когда последний умный указатель, владеющий объектом в динамической памяти, 
//  уничтожается или ему присваивается указатель на другой объект.

// В данной задаче требуется реализовать умные указатели на строки типа std::string. Но реализация не сильно зависит от самого типа объекта. 
// Создайте для типа std::string синоним с именем T с помощью using и везде далее используйте имя T. Это первый шаг к написанию шаблонного кода.

// Требования к реализации:

// using T = std::string;
// Реализуйте все методы по правилу пяти
// Реализуйте методы reset, swap, get, use_count
// Метод SharedPtr::swap реализуйте через std::swap
// Метод SharedPtr::reset напишите с использованием SharedPtr::swap
// В реализации методов переноса (move) используйте SharedPtr::swap, чтобы поменять значения указателей между текущим и временным объектом 
// (для временного объекта будет вызван деструктор)
// Перегрузите операции *, == и операцию преобразования к типу bool
// Вот пример программы, использующей класс SharedPtr:

using T = std::string;

class SharedPtr{
private:
    T* ptr = nullptr;
    int* count = nullptr;

    void release() {
        if(count){
            --(*count);
            if (count && (*count) == 0) {
                delete ptr;
                delete count;
            }
        }
    }
public:
    SharedPtr() : ptr(nullptr), count(nullptr){};
    SharedPtr(T* p) : ptr(p), count(new int(1)){};
    SharedPtr(std::nullptr_t) : SharedPtr(){};
    ~SharedPtr() {
        release();
    }

    //......................................//ready
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), count(other.count){
        if (count)
            ++(*count);
    }

    SharedPtr& operator=(const SharedPtr& other){
        if (this != &other) {
            release(); 
            ptr = other.ptr;
            count = other.count;
            if (count) 
                ++(*count);
        }
        return *this;
    }

    //....................................// ready
    SharedPtr(SharedPtr&& other) : SharedPtr(nullptr){
        swap(other);
    }

    SharedPtr& operator=(SharedPtr&& other){
        if (this != &other) {
            release();
            ptr = nullptr;
            count = nullptr;
            swap(other);
        }
        return *this;
    }

    //....................................//ready
    //reset, swap, get, use_count

    void reset(){
        SharedPtr().swap(*this);
    }

    void swap(SharedPtr &other){
        std::swap(ptr, other.ptr);
        std::swap(count, other.count);
    }

    size_t use_count() const noexcept{ 
        if(count)
            return *count; 
        return 0;
    }

    T* get() const{ 
        return ptr;
    }

    //....................................//
    // *, == и операцию преобразования к типу bool
    T& operator*() const{ 
        return *ptr;
    }

    explicit operator bool() const{ 
        return ptr != nullptr; 
    }

    bool operator==(const SharedPtr& other) const{
        return ptr == other.ptr; 
    }


};


int main()
{
    const SharedPtr p1 = new std::string("Example");
    SharedPtr p2;
    SharedPtr p3 = nullptr;
    std::cout << p1.use_count() << std::endl; // 1
    std::cout << p2.use_count() << std::endl; // 0
    std::cout << p3.use_count() << std::endl; // 0
    if (p1) {
        std::cout << *p1 << std::endl; // Example
    }
    if (p2 == p3) {
        std::cout << "p2 == p3\n"; // p2 == p3
    }
    p2 = p3 = p1;
    std::cout << p1.use_count() << std::endl; // 3
    std::cout << p2.use_count() << std::endl; // 3
    std::cout << p3.use_count() << std::endl; // 3
    std::string* pStr = p3.get();
    std::cout << *pStr << std::endl; // Example
    if (p1.get() == p2.get()) {
        std::cout << "p1 == p2\n"; // p1 == p2
    }
    p2 = std::move(p3);
    std::cout << p1.use_count() << std::endl; // 2
    std::cout << p2.use_count() << std::endl; // 2
    std::cout << p3.use_count() << std::endl; // 0
    if (p3 == nullptr) {
        std::cout << "p3 is empty\n"; // p3 is empty
    }
    SharedPtr p4(std::move(p2));
    std::cout << p1.use_count() << std::endl; // 2
    if (!p2.get()) {
        std::cout << "p2 is empty\n"; // p2 is empty
    }
}
