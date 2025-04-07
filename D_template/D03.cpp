#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>

// Решите предыдущую задачу про ввод, сортировку и вывод слов, но теперь для ввода и вывода необходимо определить шаблонные функции так, 
// чтобы задача решалась вот такой main функцией:



// #include <algorithm>
// #include <string>
// #include <vector>

// int main() {
//     std::vector<std::string> v;
//     input(v);
//     std::sort(v.begin(), v.end());
//     output(v.begin(), v.end());
//     output(v.rbegin(), v.rend());
// }

        
// Шаблонная функция input работает с любым контейнером, у которого есть базовая операция push_back добавления элемента в конец.


// template<typename T>
// void input(T& v);

        
// Шаблонная функция output работает с любым контейнером посредством итераторов.
//  Она получает два итератора и распечатывает все элементы в интервале между первым и вторым (второй не включительно).


// template<typename Iterator>
// void output(Iterator first, Iterator last);

        
// На проверку отправляйте только определения шаблонных функций. Функция main будет добавлена автоматически.

template<typename T>
void input(T& v){
    std::string ch;

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

int main(){
    std::vector <std::string> v;
    input(v);
    std::cout << "tet";
    std::sort(begin(v), end(v));
    output(v.begin(), v.end());
    output(v.rbegin(), v.rend());
}