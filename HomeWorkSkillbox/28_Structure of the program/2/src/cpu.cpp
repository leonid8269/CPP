#include "../include/cpu.h"


int64_t compute (int32_t &buf){ //! складывает все числа из оперативки

    int64_t sum {};
    for (uint8_t i = 0; i < 8 ; i++ ) sum += buf + i;

    return sum;
}