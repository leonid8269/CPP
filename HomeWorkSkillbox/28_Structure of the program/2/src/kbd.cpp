#include "../include/kbd.h"
#include "../include/ram.h"

void input (){
    for (int8_t i = 0; i < 8; ++i){
        std::cout << "Enter " << i + 1 << " number:\n";
        std::cin >> buffer[i];
    }
}