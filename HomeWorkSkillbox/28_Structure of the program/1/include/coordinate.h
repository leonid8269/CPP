#pragma once

bool stat[4]{false, false, false, false}; // статус выполнения операции.

// координаты
enum Coord{
    X,
    Y
};

//структура координат
struct point{
    double dot[2]{}; // начало реза х,у. и там где используется одиночная координата
};

// операции производимые хирургом
enum Step{
    ONE,
    TWO,
    THREE,
    FOUR
};


