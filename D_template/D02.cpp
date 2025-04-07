#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>

// Решите аналогичную задачу, но для слов, разделённых любыми пробельными символами.

// Напишите программу, которая считывает со стандартного ввода std::cin последовательность слов (пока не конец ввода),
//  сортирует их один раз и печатает отсортированную последовательность на экран в прямом и обратном порядке.

// В реализации используйте шаблоны и алгоритмы из стандартной библиотеки STL: std::vector, std::sort.
//  Обход вектора в прямом и обратном порядке выполните с использованием прямого и обратного итераторов. Для хранения слов используйте тип std::string.

// Examples
// Input
// karina elena kira anna
// margarita evdokia
// Output
// anna elena evdokia karina kira margarita 
// margarita kira karina evdokia elena anna

int main(){
    std::vector <std::string> Num;

    std::string ch;

    while(std::cin >> ch){
        // std::cout << "tut";
        Num.push_back(ch);
    }

    // std::cout << "tet";
    std::sort(begin(Num), end(Num));

    for (auto it = Num.begin(); it != Num.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << '\n';

    for (auto it = Num.rbegin(); it != Num.rend(); ++it) {
        std::cout << *it << " ";
    }
}