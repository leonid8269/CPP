#include "../include/cpu.h"


void compute (const int64_t buf[8]){

    int64_t sum {};
    for (uint8_t i = 0; i < 8 ; i++ ) sum += buf[i];
    std::cout << "The sum of numbers from RAM = " << sum << std::endl;
    }