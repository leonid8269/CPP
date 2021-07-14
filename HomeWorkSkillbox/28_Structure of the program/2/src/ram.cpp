#include "../include/ram.h"
#include "../include/kbd.h"

void write(){
    input();
}

void read(){
    for (int8_t i = 0; i < 8 ; ++i ){
        std::cout <<  "Number " << i + 1 << buffer[i] << std::endl;
    }

}