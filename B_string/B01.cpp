#include <iostream>
#include <string>
#include <algorithm>

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

    int len_a = a.size();
    int len_b = b.size();
    int ostatok = 0;
    int max_len = std::max(len_a, len_b);

    for (int i = 0; i < max_len || (ostatok != 0); i++){
        int first_index = len_a - i-1;
        if ((first_index < len_a) && (first_index >= 0)){
            num_a = HEX::hex_to_num(a[first_index]);
        }
        else
            num_a = 0;
        // std::cout<<num_a <<" first"<<std::endl;

        int sec_index = len_b - i-1;
        if ((sec_index < len_b) && (sec_index >= 0)){
            num_b = HEX::hex_to_num(b[sec_index]);
        }
        else
            num_b = 0;

        // std::cout<<num_b<<" second"<<std::endl;

        curr = (num_a + num_b + ostatok);
        ostatok = (curr) / base;

        res += HEX::value_to_hex(curr % base);
        
    }

    // res += HEX::value_to_hex(ostatok);

    // std::cout<<res << " res"<<std::endl;
    std::reverse(res.begin(), res.end());
    return res;
};


int main(void) {
    std::string first, second, res;
    std::cin >> first;
    std::cin >> second;

    // first = "AAAAAAAA";
    // second = "FFFFFF";
    res = sum(first, second);
    std::cout << res;
    return 0;
}
