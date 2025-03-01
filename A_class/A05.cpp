#include <iostream>

// Опишите абстрактный тип данных OptInt для хранения произвольных значений типа int. По умолчанию значение типа int считается не установленным. 
// Установить значение можно только явно в момент инициализации или после при помощи операции присваивания. 
// Класс OptInt должен хранить дополнительную информацию о том, установлено значение или нет.

// В реализации конструкторов рекомендуется использовать список инициализации. 
// Также можно использовать инициализацию при описании полей класса для указания значений по умолчанию. 
// Необходимо перегрузить операции << и +, чтобы они работали для объектов класса OptInt. 
// Если значение не установлено, на экран следует напечатать undefined. Если хотя бы для одного из аргументов операции + значение int не установлено,
//  то результат операции + также считается undefined.

class OptInt {
public:
    int val;
    int flag;

    OptInt(){
        val = 0;
        flag = 0; //значение еще не установлено
    }

    OptInt(int v){ //явная инициализация
        val = v;
        flag = 1;
    }

    int isSet() const {
        return flag;
    }

    friend OptInt operator+(OptInt const & x, OptInt const & y) {
        if (x.flag && y.flag){
            return OptInt(x.val + y.val);
        }
        return OptInt();
        }
};

std::ostream &operator<<(std::ostream &out, const OptInt &o) {
    if (o.flag) {
        out << o.val;
    } else {
        out << "undefined";
    }
    return out;
}

int main() {
    OptInt i;
    std::cout << i << std::endl;
    i = 5;
    if (i.isSet()) {
      std::cout << i << std::endl;
    }
    OptInt j = i, k;
    std::cout << i + j + k << std::endl;
    j = k = i + 1;
    std::cout << i + k << std::endl;
    std::cout << j << std::endl;
  
    return 0;
}
