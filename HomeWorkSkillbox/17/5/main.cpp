#include <iostream>

int main() {
    float mas[4][4] = {};
    std::cout << "Enter numbers in array: \n";
    for (int j = 0 ; j < 4 ; ++j){
        for (int i = 0; i < 4; ++i) {
            std::cin >> mas[j][i];
        }
    }

    for (int i = 0 ; i < 4; ++ i ){
        for (int j = 0 ;j < 4 ; ++j ){
           if ( i != j) mas[i][j] = 0;
        }
    }

    for (int i = 0; i < 4; ++i){
        for (int j = 0 ;j < 4 ; ++j){
            std::cout << mas[i][j] << "\t";
        }
        std::cout << std::endl;
    }



    return 0;
}
