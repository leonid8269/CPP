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

bool checkingTheRange(int a, int b){
    if  ((a >= 0 && a <= 9) && (b >= 0 && b <= 9)) return true;
    else return false;
}

bool checkDeck(int a, int  b, int c){
    if ((horizonOne != horizonTwo + 1 || horizonOne != horizonTwo - 1)  ||
        (verticalOne != verticalTwo +1 || verticalOne != verticalTwo - 1))
}


void organizationShips(char map[][10]){
    for (int count = 0; count < 10; ++ count){
        statusMap(map);
        int verticalOne = 0, horizonOne = 0;        // добавил внутрь цикла тчобы каждую итерацию они обнулялись
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

                    cout << "Excellent! It's time to mark the second point!\n";
                }
                cout << "Enter coordinate second point double-ship. (Horizontal and vertical)\n";
                cin >> horizonTwo >> verticalTwo;
                if (!(checkingTheRange(horizonTwo, verticalTwo))){
                    --count;
                    cout << "Enter the correct coordinates!! Try again!\n\a";
                    break;
                }


                if ((horizonOne != horizonTwo + 1 || horizonOne != horizonTwo - 1)  ||
                        (verticalOne != verticalTwo +1 || verticalOne != verticalTwo - 1)) {
                    --count;
                    cout << "Not excellent! Try again!\n\a";
                    break;
                }

                if (horizonTwo == horizonOne) {
                    if (verticalOne > verticalTwo){
                        verticalOne += verticalTwo;
                        verticalTwo = verticalOne - verticalTwo;
                        verticalOne -= verticalTwo;
                    }

                    for(int i = verticalOne ; i <= verticalTwo; ++i){
                        if (map[i][horizonOne] == '@'){
                            stop = false;
                            --count;
                            cout << "Not excellent! Try again!\n\a";
                            break;
                        }
                        map[i][horizonOne] = '@';
                    }
                    break;

                }else if (verticalTwo == verticalOne){
                    if (horizonOne > horizonTwo){
                        horizonOne += horizonTwo;
                        horizonTwo = horizonOne - horizonTwo;
                        horizonOne -= horizonTwo;
                    }
                    for( ; horizonOne <= horizonTwo ; ++ horizonOne){
                        if (map[verticalOne][horizonOne] == '@'){
                            stop = false;
                            --count;
                            cout << "Not excellent! Try again!\n\a";
                            break;
                        }
                        map[verticalOne][horizonOne] = '@';
                    }
                    break;
                }



            }while (stop);

//_______________________________________________________________________________________________
        }else if (count < 9) { // расстановка 3-х палубных
            cout << "It remains to put " << 9 - count << " three-deck!\n";

            do{
                cout << "Enter coordinate first point three-ship. (Horizontal and vertical)\n";
                cin >> horizonOne >> verticalOne;
                if (!(checkingTheRange(horizonOne, verticalOne))){
                    --count;
                    cout << "Enter the correct coordinates!! Try again!\n\a";
                    break;
                }

                if (map[verticalOne][horizonOne] != '.'){
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

                   // нужен цикл


            }while(true);



//_______________________________________________________________________________________________
        }else {
            cout << "It remains to put " << 10 - count << " four-deck!\n";

        }

    }
    statusMap(map); // чтобы игрок посмотрел последний раз на свое поле)
}

int main() {
    char fieldOne[10][10], fieldTwo[10][10];
    initializationMap(fieldOne);
    initializationMap(fieldTwo);

    cout << "The first player places the pieces\n";
    organizationShips(fieldOne);


    return 0;
}