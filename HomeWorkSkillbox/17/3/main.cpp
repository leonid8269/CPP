#include <iostream>

int main ( ){

    int numbers[5][5], counter = 0;
    for (int i = 0; i < 5 ; ++i) {
        for (int j = 0; j < 5; ++j) {
            ++counter;
            numbers[i][j] = counter;
        }
        ++i;
        counter += 6;
        for (int j = 0; j < 5; ++ j){
            -- counter;
            numbers[i][j] = counter;
        }
        counter += 4;
    }



    for (int i = 0;i < 5; ++i){
        for (int j = 0; j < 5;++j){
            std::cout << numbers[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}