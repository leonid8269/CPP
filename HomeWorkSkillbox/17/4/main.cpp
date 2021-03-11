#include <iostream>

using std::cin;
using std::cout;
using std::string;

string comparator (int mas1[][4], int mas2[][4]){
    for (int i = 0; i < 4 ; ++i){
        for(int j = 0;j < 4 ; ++j){
            if (mas1[i][j] != mas2[i][j]) return "No matches found!\n";
        }
    }
    return "Yes. Everything matched up\n";
}

int main() {
    int firstMas[4][4];
    int secondMas[4][4];

    cout << "Enter numbers in first array:\n";

    for (int i = 0 ;i < 4; ++i){
        for (int j = 0 ;j < 4 ; j ++){
            cin >> firstMas[i][j];
        }
    }

    cout << "Enter numbers in second array:\n";

    for (int i = 0 ;i < 4; ++i){
        for (int j = 0 ;j < 4 ; j ++){
            cin >> secondMas[i][j];
        }
    }
    cout << "\nThe result of the comparison:\n\a";
    cout << comparator(firstMas,secondMas);

    return 0;
}
