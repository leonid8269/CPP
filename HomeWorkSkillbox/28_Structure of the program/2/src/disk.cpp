#include <fstream>
#include "../include/disk.h"
#include "..//include/ram.h"

void save (){
    std::ofstream date ("../src/data.txt");
    for (int8_t i = 0; i < 8 ; ++i) date << buffer[i] << std::endl;
    date.close();

}

void load(){
    std::ifstream date ("../src/data.txt");
    if (!date.is_open()){
        std::cout << "Error opening file!\n\a";
        return;
    }else {
        int8_t i = 0;
        while (!date.eof()){
            date >> buffer[i];
            ++i;
        }
    }
    date.close();
}