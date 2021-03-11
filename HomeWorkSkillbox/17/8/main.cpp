#include <iostream>


void firstinitialization(int arr[][5][10]){

    for (int i = 0; i < 5; ++i){
        for (int j = 0 ; j < 5; ++j){
            for (int k = 0;k < 10 ; ++k){
                arr[i][j][k] = 0;
            }
        }
    }
}


int main() {

    int array[5][5][10];

    firstinitialization(array);

    std::cout << "Enter numbers from 0 to 9:\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int nBlocks;
            do {
                std::cin >> nBlocks;
                if (nBlocks < 10)
                    break;
                else
                    std::cout << "Error: number of blocks more than 9.\n";
            } while (true);
            for (int k = 0; k <= nBlocks; ++k) array[i][j][k] = k;
        }
    }

    int level;
    do {
        std::cout << "Chart level to view (0 - 9):\n";
        std::cin >> level;
    } while (level > 9);

    for (int  i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            std::cout << (array[i][j][level] == level ? "1 " : "0 ");
        std::cout << "\n";
    }

    return 0;
}