#pragma once
#include <iostream>
#include "coordinate.h"


void scalpel (point& one, point& two){
    std::cout << "Sister Scalpel!\n";
    std::cout << "Enter the coordinate of the beginning of the cut\n";
    std::cin >> one.dot[Coord::X] >> one.dot[Coord::Y];

    std::cout << "Enter the end of the end coordinate! \n";
    std::cin >> two.dot[Coord::X] >> two.dot[Coord::Y];

    std::cout << "Good!\n";

    stat[Step::ONE] = true;
}


void hemostat (point& p){
    std::cout << "Sister hemostat\n";
    std::cout << "Enter coordinates for clamping\n";

    std::cin >> p.dot[Coord::X] >> p.dot[Coord::Y];
    std::cout << "Okay, well go to the next step\n";

    stat[Step::TWO] = true;
}

void tweezers (point& p){
    std::cout << "Sister, tweezers!!\n";
    std::cout << "Enter coordinates for tweezers\n";

    std::cin >> p.dot[Coord::X] >> p.dot[Coord::Y];
    std::cout << "Done!\n";
    stat[Step::THREE] = true;
}

bool comparison(const point& one, const  point& two, const point& old_one, const point& old_two){

    if ((one.dot[Coord::X] == old_one.dot[Coord::X] && one.dot[Coord::Y] == old_one.dot[Coord::Y]) ||
        (two.dot[Coord::X] == old_two.dot[Coord::X] && two.dot[Coord::Y] == old_two.dot[Coord::Y]) ||

        (one.dot[Coord::X] == old_one.dot[Coord::Y] && one.dot[Coord::Y] == old_one.dot[Coord::X]) ||
        (two.dot[Coord::X] == old_two.dot[Coord::Y] && two.dot[Coord::Y] == old_two.dot[Coord::X]))
                return true;

    std::cout << "Coordinates did not coincide\n";
    return false;
}

void suture(point& one, point& two, const point& old_one, const point& old_two){
    std::cout << "Sister, needle!!\n";

    do {
        std::cout << "Enter the first coordinate: \n";
        std::cin >> one.dot[Coord::X] >> one.dot[Coord::Y];

        std::cout << "Enter the second coordinate: \n";
        std::cin >> two.dot[Coord::X] >> two.dot[Coord::Y];


    }while(!comparison(one, two, old_one, old_two));

    stat[Step::FOUR] = true;
}