#include <iostream>
#include <math.h>

//использорвание макросов как функции...
#define MIN(a, b) ((a < (b)) ? (a) : (b))
//!        ^
//!        1
// 1 - не должно быть пробела
#define MAX(a, b) ((a > (b)) ? (a) : (b))

int main() {
    std::cout << MIN (20,40) << std::endl;
    std::cout << MAX (20,40) << std::endl;
    std::cout << MIN (20, MIN(1,6)) << std::endl;
    std::cout << MIN (25.56, MIN(1.5,68.65)) << std::endl;


    std::cout << MAX (50.58, pow(6, 2))<< std::endl;
    //! функци я в макросе выполняется дважды. если она (функция) действительно времязатратная то ее использование в макросе не эффективно
    std::cout << ((58.58 < pow(6,2))? (58.58): (pow(6,2)));

    return 0;
}
