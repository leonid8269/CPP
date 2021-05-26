#pragma once

// координаты
enum {
    X,
    Y
};

//структура координат
struct coordinate{
    double start[2]{}; // начало реза х,у. и там где используется одиночная координата
    double stop[2]{};  // конец реза х,у
};

