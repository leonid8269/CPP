#include <iostream>

void viewMassive(int massiv[][2]){
    for(int i = 0 ;i < 6 ;++ i){
        for(int j = 0 ; j < 2 ; ++j){
            std::cout << massiv[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {

    int cutlery[6][2] = {{4,4},
                         {3,3},
                         {3,3},
                         {3,3},
                         {3,3},
                         {3,3}};

    int dishes[6][2] =  {{3,3},
                         {2,2},
                         {2,2},
                         {2,2},
                         {2,2},
                         {2,2}};

    int chair[6][2] =   {{1,1},
                         {1,1},
                         {1,1},
                         {1,1},
                         {1,1},
                         {1,1}};

    std::cout << "Cutlery (Before): \n";
    viewMassive(cutlery);

    std::cout << "Dishes (Before): \n";
    viewMassive(dishes);

    std::cout << "Chair (Before): \n";
    viewMassive(chair);

    // дама с ребенком пришла....
    chair[4][0] += 1;
    // пропала ложка...
    cutlery[2][1] -= 1;
    // вип поделился ложкой
    cutlery[2][1] += 1;
    cutlery[0][0] -= 1;
    // официант забрал тарелку у випчика c Десертом
    dishes[0][0] -= 1;

    std::cout << "Cutlery (after): \n";
    viewMassive(cutlery);

    std::cout << "Dishes (after): \n";
    viewMassive(dishes);

    std::cout << "Chair (after): \n";
    viewMassive(chair);


    return 0;
}
