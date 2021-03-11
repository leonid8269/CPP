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

void organizationShips(char map[][10]){
    for (int count = 0; count < 10; ++ count){
        statusMap(map);
        int verticalOne = 0, horizonOne = 0;        // добавил внутрь цикла тчобы каждую итерацию они обнулялись
        int verticalTwo = 0, horizonTwo = 0;

        if (count < 4) { // расстановка одно-палубных
            cout << "It remains to put " << 4 - count << " single-deck!\n";
            do {
                cout << "Enter coordinate (horizontal and vertical)\n";
                cin >> horizonOne >> verticalOne;
                map[verticalOne][horizonOne] == '.' ? (map[verticalOne][horizonOne] = '@') : --count;
                break;
            }while(true);
        }
        else if (count < 7 ) { // Расстановка 2-х палубных кораблей)
            cout << "It remains to put " << 7 - count << " double-deck!\n";
                do{
                    cout << "Enter coordinate first point double-ship. (Horizontal and vertical)\n";
                    cin >> horizonOne >> verticalOne;

                    if (map[verticalOne][horizonOne] == '.'){
                        cout << "Excellent! It's time to mark the second point!\n";
                    }else {
                        --count;
                        cout << "Not excellent! Try again!\n\a";
                        break;
                    }
                    cout << "Enter coordinate second point double-ship. (Horizontal and vertical)\n";
                    cin >> horizonTwo >> verticalTwo;

                    if((map[verticalTwo][horizonTwo] == '.') && ((horizonTwo == horizonOne &&
                            verticalTwo == (verticalOne + 1)) || (horizonTwo == horizonOne &&
                            verticalTwo == (verticalOne - 1)) || (horizonTwo == (horizonOne - 1) &&
                            verticalOne == verticalTwo) || (horizonTwo == (horizonOne + 1) &&
                            verticalOne == verticalTwo))){
                        map[verticalOne][horizonOne] = '@';
                        map[verticalTwo][horizonTwo] = '@';
                        cout << "Excellent!!\n";
                        break;
                    }else {
                        cout << "Not excellent, try again!\n\a";
                        --count;
                        break;
                    }
                }while (true);


        }else if (count < 9) { // расстановка 3-х палубных
            cout << "It remains to put " << 9 - count << " three-deck!\n";

                do{
                    cout << "Enter coordinate first point three-ship. (Horizontal and vertical)\n";
                    cin >> horizonOne >> verticalOne;

                    if (map[verticalOne][horizonOne] == '.'){
                        cout << "Excellent! It's time to mark the END point!\n";
                    }else {
                        --count;
                        cout << "Not excellent! Try again!\n\a";
                        break;
                    }

                    cout << "Enter coordinate END point three-ship. (Horizontal and vertical)\n";
                    cin >> horizonTwo >> verticalTwo;

                    if (map[verticalTwo][horizonTwo] == '@') {
                        cout << "NOT excellent, try again!\n\a";
                        -- count;
                        break;

                    }else {

                        // застрял тут!

                    }
                }while(true);




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