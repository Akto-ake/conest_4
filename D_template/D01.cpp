#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// Напишите программу, которая считывает со стандартного ввода std::cin последовательность целых чисел типа int (пока не конец ввода), 
// сортирует их один раз и печатает отсортированную последовательность на экран в прямом и обратном порядке.

// В реализации используйте шаблоны и алгоритмы из стандартной библиотеки STL: std::vector, std::sort. 
// Обход вектора в прямом и обратном порядке выполните с использованием прямого и обратного итераторов.

// Examples
// Input
// 5 17 -3 0 19 5 34 -12
// Output
// -12 -3 0 5 5 17 19 34 
// 34 19 17 5 5 0 -3 -12
 

int main(){
    std::vector <int> Num;

    int ch = 0;

    while(std::cin >> ch){
        Num.push_back(ch);
    }

    std::sort(begin(Num), end(Num));
    
    for (auto it = Num.begin(); it != Num.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << '\n';

    for (auto it = Num.rbegin(); it != Num.rend(); ++it) {
        std::cout << *it << " ";
    }
}