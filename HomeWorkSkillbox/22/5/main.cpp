#include <iostream>
#include <fstream>

void roulette (int* arr, int& motion ){ // возвращает инт - вариант вопроса при "проскальзывании" волчка
    using namespace std;
    cout << "How much to rotate the top? \n";
    cin >> motion;
    if (motion > 12 ) motion /= 12; // даже если получится дробное число это неимеет значения, волчек же не перешел границу ячейки заничт он выбирает ту ечейку на которую указыват...
    while(true){
        if (arr[motion - 1 ] == 0) motion ++;
        else{
            arr[motion - 1] = 0;
            return;
        }

    }

}

void answer (){

}

std::string question ( ){

}

void processGame (int& player, int& viewer){

    bool gameOver = false;

    while (!gameOver){
        if (player)

    }



}


int main() {
    using namespace std;
    int motion = 0;

    int variants[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int pointsPlayer = 0;
    int pointsViewer = 0;






    return 0;
}
