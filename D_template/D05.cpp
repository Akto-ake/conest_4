#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>

// Решите предыдущую задачу про выбор чётных чисел, но теперь для фильтрации элементов контейнера необходимо определить 
// шаблонную функцию так, чтобы задача решалась вот такой функцией main:



// #include <vector>

// bool isChet(int x) {
//     return x % 2 == 0;
// }

// int main() {
//     std::vector<int> v;
//     input(v);
//     filter(v, isChet);
//     output(v.begin(), v.end());
// }

        
// Шаблонная функция filter работает с любым контейнером, у которого есть базовая операция erase удаления элемента.


// template<typename T, typename Function>
// void filter(T& container, Function predicate);

        
// На проверку отправляйте только определения шаблонных функций вместе с необходимыми include-директивами. 
// Функции isChet и main будут добавлены автоматически.

// Examples
// Input
// 5 17 -3 0 19 5 34 -12
// Output
// 0 34 -12
 

template<typename T>
void input(T& v){
    int ch;

    while((std::cin >> ch)){
        v.push_back(ch);
    }   
}

template<typename Iterator>
void output(Iterator first, Iterator last){
    for (auto it = first; it != last; it++) {
        std::cout << *it << " ";
    }
    std::cout << '\n';
}

bool isChet(int x) {
    return x % 2 == 0;
}

template<typename T, typename Function>
void filter(T& v, Function predicate){
    auto iter = std::remove_if( v.begin(), v.end(),
        [&predicate](auto x) { return !predicate(x); }
    );
    v.erase(iter, v.end());
}


int main() {
    std::vector<int> v;
    input(v);
    filter(v, isChet);
    output(v.begin(), v.end());
}