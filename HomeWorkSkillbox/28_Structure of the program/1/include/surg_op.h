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

void scalpel (coordinate& coor);

void hemostat (coordinate& coor);

void tweezers (coordinate& coor);

bool comparison(const coordinate& coor, const coordinate& old);

void suture(coordinate& coor, const coordinate& old);