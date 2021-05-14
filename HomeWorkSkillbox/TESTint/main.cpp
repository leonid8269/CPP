#include <iostream>
#include <cstdint>
#include <map>

int main(){
    int32_t length{};
    int32_t sign{};
    while (true) {
        length = -1;
        sign = -1;

        std::cout << "length: \n";
        while (length < 0) std::cin >> length;
        std::cout << "sign: \n";
        while (sign < 0) std::cin >> sign;
        if (length + sign < 40) break;
    }

    for (int i = 0; i < length + sign; ++i){
        if (i < length / 2) std::cout << '!';
        else if (i < (length / 2) + sign) std::cout << '~';
        else std::cout << '!';
    }


    return 0;
}

