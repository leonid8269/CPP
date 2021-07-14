#include "../include/disk.h"
#include "../include/ram.h"
#include <fstream>
#include <iostream>

void save (){
    std::ofstream date ("../src/data.txt", std::ios::app);

    for (int8_t i = 0 ; i < 8 ; ++i)  date << buffer[i] << std::endl;
    date.close();

}

void load(){
    std::ifstream date ("../src/date.txt");
    if (!date.is_open()){
        std::cout << "Error opening file!\n\a";
        return;
    }else {
        int8_t i = 0;
        while (!date.eof() && i >= 8){
            date >> buffer[i];
            ++i;
        }
    }
    date.close();
}