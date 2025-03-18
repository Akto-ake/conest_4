#include <iostream>
#include <string>
#include <algorithm>

//NOT WORK

constexpr int base = 16;

namespace HEX {

    int hex_to_num(char symbol) {
        if (symbol >= '0' && symbol <= '9') {
            return symbol - '0';
        } else {
            if ((10 + (symbol - 'A')) < base)
                return 10 + (symbol - 'A');
        }
        return 0;
    }

    char value_to_hex(int symbol) {
        if (symbol < 10) {
            return '0' + symbol;
        } else {
            return 'A' + (symbol - 10);
        }
    }
}

std::string sum(const std::string& a, const std::string& b){
    std::string res = "";
    int num_a = 0;
    int num_b = 0;
    int curr = 0;
    int k = 1;
    
    int len_a = a.size();
    int len_b = b.size();

    for (int i = len_a - 1; i >= 0; i--){
        curr = HEX::hex_to_num(a[i]);
        // std::cout << curr<<std::endl;
        num_a += curr * k;
        k *= base;
    }
    // std::cout << num_a<<std::endl;
    k = 1;

    for (int i = 0; i < len_b; i++){
        curr = HEX::hex_to_num(b[i]);
        num_b += curr * k;
        k *= base;
    }
    // std::cout << num_b<<std::endl;

    int num_res = num_a + num_b;
    // std::cout << num_res <<std::endl; 

    while(num_res >= base){
        curr = num_res % base;
        res+= HEX::value_to_hex(curr);

        num_res /= base;
    }

    curr = num_res % base;
    res+= HEX::value_to_hex(curr);
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    std::string first, second, res;
    std::cin >> first;
    std::cin >> second;

    // first = "2";
    // second = "F";
    res = sum(first, second);
    std::cout << res;
    return 0;
}
