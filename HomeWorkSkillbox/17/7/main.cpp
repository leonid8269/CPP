#include <iostream>

using std::cin;
using std::cout;
using std::endl;


void initializationPimple(bool array[][12]){ // инициализация пупырки
    for (int i = 0 ; i < 12 ;++ i){
        for (int j = 0; j < 12; ++ j ){
            array[i][j] = true;
        }
    }
}

void statusGame(bool array[][12]){

    for (int i = 0 ; i < 12; ++ i){
        for (int j = 0; j < 12; ++ j){
            if (array[i][j]) cout << 'o';
            else cout << 'x';
        }
        cout << endl;
    }
}

bool gameOver(bool arr[][12]){
    int chek = 12*12;
    for (int i = 0; i < 12 ; ++i){
        for (int j = 0; j < 12; ++j) {
            if (!arr[i][j]) --chek;
        }
    }
    if (!chek) return true;
    return false;
}


void processGame (bool arr[][12]){

    int coordinate1 = 0, coordinate2 = 0, coordinate3 = 0, coordinate4 = 0;
    bool flag = true;
    while (flag) {
        cout << "Enter the first coordinates [x:y]\n";
        cin >> coordinate1 >> coordinate2;
        if (coordinate1 > 11 || coordinate1 < 0) {
            flag = true;
            cout << "Try again!!!\n";
        } else flag = false;
    }
        flag = true;
    while (flag) {
        cout << "Enter the second coordinates[x:y]\n";
        cin >> coordinate3 >> coordinate4;
        if (coordinate3 > 11 || coordinate4 < 0) {
            flag = true;
            cout << "Try again!!!\n";
        } else flag = false;
    }

    if ((coordinate1 == coordinate3) && (coordinate2 == coordinate4)){ // 1 вариант - единичный.
        int i = 11 - coordinate4 , j = coordinate1 ;
        if (arr[i][j]) cout << "!!!POP!!!\a\n";
        arr[i][j] = false;
    }else  if (coordinate2 == coordinate4 ) { // 2 вариант горизонтальный

        if (coordinate1 > coordinate3) {  // она пригодилась как оказалось, на первых занятиях помнишь?)
            coordinate1 += coordinate3;
            coordinate3 = coordinate1 - coordinate3;
            coordinate1 -= coordinate3;
        }
        for (int  i = 11 - coordinate2, j = coordinate1; j <= coordinate3; ++j) {
            if (arr[i][j]) cout << "!!!POP!!!\a\n";
            arr[i][j] = false;
        }

    } else if (coordinate1 == coordinate3) { // 3 вариант вертикальный
        if (coordinate4 > coordinate2){
            coordinate3 += coordinate2;
            coordinate2 = coordinate4 - coordinate2;
            coordinate4 -= coordinate2;
        }
        for (int i = 11 - coordinate2 , j = coordinate3 ; i <= 11 - coordinate4  ; ++ i){
            if (arr[i][j]) cout << "!!!POP!!!\a\n";
            arr[i][j] = false;
        }
    } else { // остальные варианты записываю в разных вариациях... без подмены значений
        if (coordinate1 < coordinate3 && coordinate2 > coordinate4){
            for (int i = 11 - coordinate2; i <= 11 - coordinate4; ++i){
                for (int j = coordinate1; j <= coordinate3; ++j){
                    if (arr[i][j]) cout << "!!!POP!!!\a\n";
                    arr[i][j] = false;
                }
            }
        }else if (coordinate1 > coordinate3 && coordinate2 < coordinate4){
            for (int i = 11 - coordinate4; i <= 11 - coordinate2; ++i){
                for (int j = coordinate3; j<= coordinate1; ++j){
                    if (arr[i][j]) cout << "!!!POP!!!\a\n";
                    arr[i][j] = false;
                }
            }
        }else if (coordinate1 < coordinate3 && coordinate2 < coordinate4){
            for (int i = 11 - coordinate4; i <= 11 - coordinate2; ++i ){
                for (int j = coordinate1; j <= coordinate3; ++j){
                    if (arr[i][j]) cout << "!!!POP!!!\a\n";
                    arr[i][j] = false;
                }
            }
        }else {
            for (int i = 11 - coordinate2; i <= 11 - coordinate4; ++i ){
                for(int j = coordinate3; j <= coordinate1; ++j ){
                    if (arr[i][j]) cout << "!!!POP!!!\a\n";
                    arr[i][j] = false;
                }
            }
        }
    }
}

int main() {
    bool arrayPimple[12][12]; // массив пупырок

    initializationPimple(arrayPimple);

    while (!gameOver(arrayPimple)){
        statusGame(arrayPimple);
        processGame(arrayPimple);
    }
    statusGame(arrayPimple);
    return 0;
}
