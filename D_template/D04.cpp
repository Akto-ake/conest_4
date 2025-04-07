#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>

// Напишите программу, которая считывает со стандартного ввода std::cin последовательность целых чисел типа int (пока не конец ввода),
//  сохраняет их в контейнер, затем выбирает только чётные числа, сохраняет их в другой контейнер в том же порядке и затем печатает их на экран.

// В реализации используйте шаблон std::vector и шаблонные функции input и output, описанные в предыдущем задании.

// В функции main сразу определите синоним для контейнера:
// using T = vector<int>;
// и далее везде используйте имя T.

// Для обхода значений коллекции используйте новую форму цикла for:
// for (T::value_type& elem : vec) { ... }
// , где value_type — это синоним для типа элементов, определённый в каждой коллекции из библиотеки STL;
// или
// for (auto& elem : vec) { ... }
// , где auto будет обозначать тип элементов коллекции.

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

int main(){
    using T = std::vector <int>;
    T v, v_chet;

    input(v);

    for (auto elem : v){
        if (!(elem % 2)){
            v_chet.push_back(elem);
        }
    }

    output(v_chet.begin(), v_chet.end());
}