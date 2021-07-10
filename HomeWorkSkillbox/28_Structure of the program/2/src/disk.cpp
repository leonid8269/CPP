#include "../include/disk.h"
#include <fstream>
#include <iostream>

void save (){
    std::ifstream date ("../src/data.txt");
    if(!date.is_open()){
        std::cout << "Error, opening file!\n";
        return;
    }else {
        
    }
    date.close();

}

void load(){


}