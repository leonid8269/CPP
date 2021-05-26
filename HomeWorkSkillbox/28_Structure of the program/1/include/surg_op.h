#pragma once
#include <iostream>
#include "coordinate.h"

bool stat[4]{false, false, false, false}; // статус выполнения операции.

// операции производимые хирургом
enum {
    ONE_STEP,
    TWO_STEP,
    THREE_STEP,
    FOUR_STEP
};

void scalpel (coordinate& coor){
    std::cout << "Sister Scalpel!\n";

    std::cout << "Enter the coordinate of the beginning of the cut! [x:y]\n";
    std::cin >> coor.start[X] >> coor.start[Y];

    std::cout << "Enter the end of the end coordinate! [x:y]\n";
    std::cin >> coor.stop[X] >> coor.stop[Y];

    std::cout << "Surgical cut performed!\n";
    stat[ONE_STEP] = true;
}


void hemostat (coordinate& coor){
    std::cout << "Sister hemostat\n";

    std::cout << "Enter coordinates for clamping\n";
    std::cin >> coor.start[X] >> coor.start[Y];

    std::cout << "Okay, well go to the next step\n";

    stat[TWO_STEP] = true;
}

void tweezers (coordinate& coor){
    std::cout << "Sister, tweezers!!\n";

    std::cout << "Enter coordinates for tweezers\n";
    std::cin >> coor.start[X] >> coor.start[Y];

    std::cout << "Done!\n";

    stat[THREE_STEP] = true;
}

bool comparison(const coordinate& coor, const coordinate& old){
    if (coor.start[X] == old.start[X] && coor.stop[Y] == old.stop[Y]) return true;

    std::cout << "Coordinates did not coincide\n";
    return false;
}

void suture(coordinate& coor, const coordinate& old){

    std::cout << "Sister, needle!!\n";
    do {
        std::cout << "Enter first coordinate!\n";
        std::cin >> coor.start[X] >> coor.start[Y];
        std::cin >> coor.stop[X] >> coor.stop[Y];
    }while(!comparison(coor, old));


    stat[FOUR_STEP] = true;
}