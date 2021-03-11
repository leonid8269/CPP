#include <iostream>

using std::cout;
using std::cin;
using std::string;

char game[3][3] = {{'.', '.', '.'},  // 7   8   9
                   {'.', '.', '.'},  // 4   5   6
                   {'.', '.', '.'}}; // 1   2   3

bool Progress(int answerX, int answerO){

    if (answerX == 1 && ::game[2][0] == '.') {
        ::game[2][0] = 'X';
        return true;
    }
    else if (answerX == 2 && ::game[2][1] == '.') {
        ::game[2][1] = 'X';
        return true;
    }
    else if (answerX == 3 && ::game[2][2] == '.') {
        ::game[2][2] = 'X';
        return true;
    }
    else if (answerX == 4 && ::game[1][0] == '.') {
        ::game[1][0] = 'X';
        return true;
    }
    else if (answerX == 5 && ::game[1][1] == '.') {
        ::game[1][1] = 'X';
        return true;
    }
    else if (answerX == 6 && ::game[1][2] == '.') {
        ::game[1][2] = 'X';
        return true;
    }
    else if (answerX == 7 && ::game[0][0] == '.') {
        ::game[0][0] = 'X';
        return true;
    }
    else if (answerX == 8 && ::game[0][1] == '.') {
        ::game[0][1] = 'X';
        return true;
    }
    else if (answerX == 9 && ::game[0][2] == '.') {
        ::game[0][2] = 'X';
        return true;
    }


    if (answerO == 1 && ::game[2][0] == '.') {
        ::game[2][0] = 'O';
        return true;
    }
    else if (answerO == 2 && ::game[2][1] == '.') {
        ::game[2][1] = 'O';
        return true;
    }
    else if (answerO == 3 && ::game[2][2] == '.') {
        ::game[2][2] = 'O';
        return true;
    }
    else if (answerO == 4 && ::game[1][0] == '.') {
        ::game[1][0] = 'O';
        return true;
    }
    else if (answerO == 5 && ::game[1][1] == '.') {
        ::game[1][1] = 'O';
        return true;
    }
    else if (answerO == 6 && ::game[1][2] == '.') {
        ::game[1][2] = 'O';
        return true;
    }
    else if (answerO == 7 && ::game[0][0] == '.') {
        ::game[0][0] = 'O';
        return true;
    }
    else if (answerO == 8 && ::game[0][1] == '.') {
        ::game[0][1] = 'O';
        return true;
    }
    else if (answerO == 9 && ::game[0][2] == '.') {
        ::game[0][2] = 'O';
        return true;
    }


    return false;
} // изменение игрового поля при правильных ходах


void statusGame(){
    for (int i = 0;i < 3 ;++ i){
        for (int j = 0;j < 3 ; ++ j){
            cout << ::game[i][j] << ' ';
        }
        cout << std::endl;
    }
} // показывает поле

void whoWon (char won) {
    if (won == 'X') cout << "X - victory! \n";
    else if (won == 'O')  cout << "O - Victory\n";
    else if (won == 'Z') cout << "End of moves\n";

}

bool gameOver() { // завершение игры (когда конец ходов или кончается поле)


    for (int i = 0; i < 3; ++i) { // проверка по горизонту
        int sumX = 0, sumO = 0;
        for (int j = 0; j < 3; ++j) {
            if (::game[i][j] == 'X') ++sumX;
            else if (::game[i][j] == 'O') ++sumO;
        }
        if (sumX == 3) {
            char won = 'X';
            whoWon(won);
            return false;
        } else if (sumO == 3) {
            char won = 'O';
            whoWon(won);
            return false;

        }
    }

    for (int i = 0; i < 3; ++i) { // Проверка вертикалей
        int sumX = 0, sumO = 0;
        for (int j = 0; j < 3; ++j) {
            if (::game[j][i] == 'X') ++sumX;
            else if (::game[j][i] == 'O') ++sumO;
        }
        if (sumX == 3) {
            char won = 'X';
            whoWon(won);
            return false;
        } else if (sumO == 3) {
            char won = 'O';
            whoWon(won);
            return false;
        }
    }

    for (int i = 0,sumX = 0, sumO = 0; i < 3; ++i) { // диагональ
        if (::game[i][i] == 'X') ++sumX;
        else if (::game[i][i] == 'O') ++sumO;
        if (sumX == 3) {
            char won = 'X';
            whoWon(won);
            return false;
        } else if (sumO == 3) {
            char won = 'O';
            whoWon(won);
            return false;
        }
    }




    if (::game[2][0] == 'X' && ::game[1][1] == 'X' && ::game[0][2] == 'X') { // диагональ
        char won = 'X';
        whoWon(won);
        return false; // X victory
    }
    else if (::game[2][0] == 'O' && ::game[1][1] == 'O' && ::game[0][2] == 'O') { // диагональ

        char won = 'O';
        whoWon(won);
        return false; // O victory
    }


    for (int i = 0, sumSymbol = 9;i < 3;++ i){
        for (int j = 0;j < 3; ++j){
            if (::game[i][j] != '.')  -- sumSymbol;
            if (sumSymbol == 0) {
                char won = 'Z';
                whoWon(won);
                return false;
            }
        }
    }

    return true;

    }


int main() {
    bool end = true;
    while(end) {
        statusGame();
        for (int answerX = 0; !Progress(answerX, 0);) { // Ход первого игрока
            cout << "Where to put 'X'??\n";
            if (!gameOver()) { // Проверяем завершилась игра или нет
                end = false;
                break;
            }
            cin >> answerX;
            if (answerX == 0) return 0 ;
        }
        statusGame();

        if (!gameOver()) break; // чтобы не просил ход у 'O'

        for (int answerO = 0; !Progress(0, answerO);) { // ход второго
            cout << "Where to put 'O'???\n";
            if (!gameOver()) {
                end = false;
                break;
            }
            cin >> answerO;
            if (answerO == 0) return 0;
        }

    }


    return 0;
}
