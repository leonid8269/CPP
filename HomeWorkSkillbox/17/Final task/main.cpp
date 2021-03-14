#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;


void initializationMap(char map[][10]) {
    for (int i = 0; i < 10; ++i){
        for(int j = 0;j < 10 ;++j){
            map[i][j] = '.';
        }
    }
}


void statusMap(char map[][10]){
    cout << "   0 1 2 3 4 5 6 7 8 9\n";
    cout << "   -------------------\n";

    for (int i = 0; i < 10; ++i){
        cout << i << " |";
        for(int j = 0;j < 10 ;++j){
            cout << "" << map[i][j] << " ";
        }
        cout << endl;
    }
}

void statusMapInGame(char map[][10]){ // доделать вывод  попал и промах.
    cout << "   0 1 2 3 4 5 6 7 8 9\n";
    cout << "   -------------------\n";

    for (int i = 0; i < 10; ++i){
        cout << i << " |";
        for(int j = 0;j < 10 ;++j){
            if (map[i][j] == '.' || map[i][j] == '@') cout << ". ";
            else cout << map[i][j] << " ";
        }
        cout << endl;
    }
}


bool checkingTheRange(int a, int b){
    if  ((a >= 0 && a <= 9) && (b >= 0 && b <= 9)) return true;
    else return false;
}

bool checkDeck(int horizonOne, int horizonTwo, int verticalOne ,int verticalTwo ,int magnificationStep){
    if (horizonOne == horizonTwo){
        if ((verticalOne == verticalTwo + magnificationStep)
            || (verticalOne == verticalTwo - magnificationStep))  return true;
        else return false;

    } else if (verticalOne == verticalTwo){
        if ((horizonOne == horizonTwo + magnificationStep)
            || (horizonOne == horizonTwo - magnificationStep)) return true;
        else return false;

    }else return false;


}
void substitute(int& first, int& second){
    first += second;
    second = first - second;
    first -= second;

}

void organizationShips(char map[][10]){
    for (int count = 0; count < 10; ++ count){
        statusMap(map);
        int verticalOne = 0, horizonOne = 0;
        int verticalTwo = 0, horizonTwo = 0;
//_______________________________________________________________________________________________
        if (count < 4) { // расстановка одно-палубных
            cout << "It remains to put " << 4 - count << " single-deck!\n";
            do {
                cout << "Enter coordinate (horizontal and vertical)\n";
                cin >> horizonOne >> verticalOne;

                if (!(checkingTheRange(horizonOne, verticalOne))){
                    --count;
                    cout << "Enter the correct coordinates!! Try again!\n\a";
                    break;
                }

                if (map[verticalOne][horizonOne] != '.') {
                    --count;
                    cout << "Not excellent! Try again!\n\a";
                }else {
                    (map[verticalOne][horizonOne] = '@');
                    cout << "Excellent!\n";
                }
                break;
            }while(true);
        }

//_______________________________________________________________________________________________
        else if (count < 7 ) { // Расстановка 2-х палубных кораблей)
            cout << "It remains to put " << 7 - count << " double-deck!\n";
            bool stop;
            do{
                stop = true;
                cout << "Enter coordinate first point double-ship. (Horizontal and vertical)\n";
                cin >> horizonOne >> verticalOne;
                if (!(checkingTheRange(horizonOne, verticalOne))) {
                    --count;
                    cout << "Enter the correct coordinates!! Try again!\n\a";
                    break;
                }

                if (map[verticalOne][horizonOne] == '@'){
                    --count;
                    cout << "Not excellent! Try again!\n\a";
                    break;
                }else {

                    cout << "Excellent! It's time to mark the END point!\n";
                }
                cout << "Enter coordinate END point double-ship. (Horizontal and vertical)\n";
                cin >> horizonTwo >> verticalTwo;
                if (!(checkingTheRange(horizonTwo, verticalTwo))){
                    --count;
                    cout << "Enter the correct coordinates!! Try again!\n\a";
                    break;
                }

                if (!(checkDeck(horizonOne,horizonTwo,verticalOne,verticalTwo,1))) {
                    --count;
                    cout << "Not excellent! Try again!\n\a";
                    break;
                }

                if (horizonTwo == horizonOne) {
                    if (verticalOne > verticalTwo){
                        substitute(verticalOne,verticalTwo);
                    }

                    for(int i = verticalOne ; i <= verticalTwo; ++i){
                        if (map[i][horizonOne] == '@'){
                            stop = false;
                            --count;
                            cout << "Not excellent! Try again!\n\a";
                            break;
                        }
                    }

                    if (stop){
                        for(int i = verticalOne ; i <= verticalTwo; ++i){
                            map[i][horizonOne] = '@';
                            }
                        }
                    break;

                }else if (verticalTwo == verticalOne){
                    if (horizonOne > horizonTwo){
                        substitute(horizonOne, horizonTwo);
                    }
                    for( int i = horizonOne; i <= horizonTwo ; ++ i){
                        if (map[verticalOne][i] == '@'){
                            stop = false;
                            --count;
                            cout << "Not excellent! Try again!\n\a";
                            break;
                        }
                    }

                    if (stop){
                        for(int i = horizonOne ; i <= horizonTwo; ++i){
                            map[verticalOne][i] = '@';
                        }
                    }
                    break;
                }

            }while (true);

//_______________________________________________________________________________________________
        }else if (count < 9) { // расстановка 3-х палубных
            cout << "It remains to put " << 9 - count << " three-deck!\n";

            bool stop;
            do{
                stop = true;
                cout << "Enter coordinate first point three-ship. (Horizontal and vertical)\n";
                cin >> horizonOne >> verticalOne;
                if (!(checkingTheRange(horizonOne, verticalOne))) {
                    --count;
                    cout << "Enter the correct coordinates!! Try again!\n\a";
                    break;
                }

                if (map[verticalOne][horizonOne] == '@'){
                    --count;
                    cout << "Not excellent! Try again!\n\a";
                    break;
                }else {

                    cout << "Excellent! It's time to mark the END point!\n";
                }
                cout << "Enter coordinate END point three-ship. (Horizontal and vertical)\n";
                cin >> horizonTwo >> verticalTwo;
                if (!(checkingTheRange(horizonTwo, verticalTwo))){
                    --count;
                    cout << "Enter the correct coordinates!! Try again!\n\a";
                    break;
                }

                if (!(checkDeck(horizonOne,horizonTwo,verticalOne,verticalTwo,2))) {
                    --count;
                    cout << "Not excellent! Try again!\n\a";
                    break;
                }

                if (horizonTwo == horizonOne) {
                    if (verticalOne > verticalTwo){
                        substitute(verticalOne,verticalTwo);
                    }

                    for(int i = verticalOne ; i <= verticalTwo; ++i){
                        if (map[i][horizonOne] == '@'){
                            stop = false;
                            --count;
                            cout << "Not excellent! Try again!\n\a";
                            break;
                        }
                    }

                    if (stop){
                        for(int i = verticalOne ; i <= verticalTwo; ++i){
                            map[i][horizonOne] = '@';
                        }
                    }
                    break;

                }else if (verticalTwo == verticalOne){
                    if (horizonOne > horizonTwo){
                        substitute(horizonOne, horizonTwo);
                    }
                    for( int i = horizonOne; i <= horizonTwo ; ++ i){
                        if (map[verticalOne][i] == '@'){
                            stop = false;
                            --count;
                            cout << "Not excellent! Try again!\n\a";
                            break;
                        }
                    }

                    if (stop){
                        for(int i = horizonOne ; i <= horizonTwo; ++i){
                            map[verticalOne][i] = '@';
                        }
                    }
                    break;
                }

            }while (true);

//_______________________________________________________________________________________________
        }else {
            cout << "It remains to put " << 10 - count << " four-deck!\n";
            bool stop;
            do{
                stop = true;
                cout << "Enter coordinate first point four-ship. (Horizontal and vertical)\n";
                cin >> horizonOne >> verticalOne;
                if (!(checkingTheRange(horizonOne, verticalOne))) {
                    --count;
                    cout << "Enter the correct coordinates!! Try again!\n\a";
                    break;
                }

                if (map[verticalOne][horizonOne] == '@'){
                    --count;
                    cout << "Not excellent! Try again!\n\a";
                    break;
                }else {

                    cout << "Excellent! It's time to mark the END point!\n";
                }
                cout << "Enter coordinate END point four-ship. (Horizontal and vertical)\n";
                cin >> horizonTwo >> verticalTwo;
                if (!(checkingTheRange(horizonTwo, verticalTwo))){
                    --count;
                    cout << "Enter the correct coordinates!! Try again!\n\a";
                    break;
                }

                if (!(checkDeck(horizonOne,horizonTwo,verticalOne,verticalTwo,3))) {
                    --count;
                    cout << "Not excellent! Try again!\n\a";
                    break;
                }

                if (horizonTwo == horizonOne) {
                    if (verticalOne > verticalTwo){
                        substitute(verticalOne,verticalTwo);
                    }

                    for(int i = verticalOne ; i <= verticalTwo; ++i){
                        if (map[i][horizonOne] == '@'){
                            stop = false;
                            --count;
                            cout << "Not excellent! Try again!\n\a";
                            break;
                        }
                    }

                    if (stop){
                        for(int i = verticalOne ; i <= verticalTwo; ++i){
                            map[i][horizonOne] = '@';
                        }
                    }
                    break;

                }else if (verticalTwo == verticalOne){
                    if (horizonOne > horizonTwo){
                        substitute(horizonOne, horizonTwo);
                    }
                    for( int i = horizonOne; i <= horizonTwo ; ++ i){
                        if (map[verticalOne][i] == '@'){
                            stop = false;
                            --count;
                            cout << "Not excellent! Try again!\n\a";
                            break;
                        }
                    }

                    if (stop){
                        for(int i = horizonOne ; i <= horizonTwo; ++i){
                            map[verticalOne][i] = '@';
                        }
                    }
                    break;
                }

            }while (true);
        }
    }

    statusMap(map); // чтобы игрок посмотрел последний раз на свое поле)
    cout << "Memorize your field!!\n";
    system("pause");
    cout << " \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

bool gameOver(char map[][10]){

    int hitCounter = 0;
    for (int i = 0; i < 10; ++i){
        for (int j = 0 ; j < 10 ;++ j){
            if (map[i][j] == 'X') ++ hitCounter;
        }
    }
    if (hitCounter == (1+1+1+1) + (2+2+2) + (3+3) + 4) return true;

    return false;
}


void processGame(char map[][10], bool& hit){ // Реализация хода игроков
    statusMapInGame(map);
    int attackCoordinateOne = 0, attackCoordinateTwo = 0;
    do {
        cout << "At what coordinate will we fire?\n";
        cin >> attackCoordinateTwo >> attackCoordinateOne;
    }while (!(checkingTheRange(attackCoordinateOne,attackCoordinateTwo)));

    if (map[attackCoordinateOne][attackCoordinateTwo] == '.'){
        hit = false;
        cout << "MISS!\n";
        map[attackCoordinateOne][attackCoordinateTwo] = 'O';

    }else if (map[attackCoordinateOne][attackCoordinateTwo] == 'O'
            || map[attackCoordinateOne][attackCoordinateTwo] == 'X'){
        cout << "The fire was fired at this coordinate!! Try again!!\n";
        hit = true; // только таким образом я могу повторить попытку
    } else {
        hit = true;
        cout << "HIT!\n\a";
        map[attackCoordinateOne][attackCoordinateTwo] = 'X';
    }


}

int main() {
    char fieldOne[10][10], fieldTwo[10][10];
    initializationMap(fieldOne);
    initializationMap(fieldTwo);

    cout << "The first player places the pieces\n\a";
    organizationShips(fieldOne);

    cout << "The second player places the pieces\n\a";
    organizationShips(fieldTwo);

    bool hit = false;
    while (true){
//___________________________________________________________________________// здесь осущетвляется ход первого игрока
        cout << "\nFirst player's turn\n";
        do {
            processGame(fieldTwo, hit);

        }while(hit && !gameOver(fieldTwo)); // если промах то ход переходитследующему или пока игра не кончится.

        if (gameOver(fieldTwo)) {
            cout << "Victory! First Player!!!\n";
            break;
        }
//___________________________________________________________________________

        cout << "\nSecond player's turn\n";
        do{
            processGame(fieldOne, hit);
        }while(hit && !gameOver(fieldOne));


        if (gameOver(fieldOne)) {
            cout << "Victory First Player!!!\n";
            break;
        }
    }

//___________________________________________________________________________


    cout << "\n\n\n\n\n\nEach player shows his cards\n";
    cout << "Map first player: \n";
    statusMap(fieldOne);

    cout << "\n\n\n\n\nMap second player: \n";
    statusMap(fieldTwo);

    cout << "Thanks for the game\n";

    return 0;
}