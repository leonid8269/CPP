#include <iostream>
#include "my_math.h"
#include "my_math.h" //! в данном случае будет куча ошубок так как одно и тоде содержание
                     //! если в заг. файле не включенн #pragma once


int main() {

    std::cout << circumference(5.6);


    return 0;
}
