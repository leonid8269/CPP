//Задача 1. Корабли в “морском бое”
//
//Требуется объявить массивы для игры в морской бой и вывести их размеры в консоль, не
//используя констант с размерами. Всего таких типов 4: крошечный, малый, средний и большой.
//Для простоты, типом элементов корабля могут быть обычные bool (размер 1 байт).


#include <iostream>

using std::cout;
using std::endl;

int main() {
    bool nano[1];
    bool micro[2];
    bool big[3];
    bool grand[4];

    cout << "\t\tSize ships!" << endl;
    cout << "Nano-Ship: "  << sizeof (nano) << endl;
    cout << "Micro-Ship: " << sizeof (micro) << endl;
    cout << "Big-Ship: "   << sizeof (big) << endl;
    cout << "Grand-Ship: " << sizeof(grand)<< endl;



    return 0;
}
