//! перечисления enum


#include <iostream>

using namespace std;

enum switches{
    OUTLETS_FLOOR_1 = 1,    //  1  =      1
    LIGHT_FLOOR_1 = 2,      //  2  =     10
    OVEN = 4,               //  4  =    100
    BOILER = 8,             //  8  =   1000
    OUTLETS_FLOOR_2 = 16,   //  16 =  10000
    LIGHT_FLOOR_2 = 32      //  32 = 100000    кратно 2х для того чтобы
                            // именно по этому пишем так,
                            // чтобы побитово понять содержит ли в себе state эти константы

};



enum status{
    UNKNOWN = -1,// ТАК ЖЕ МОЖНО ПРИСВАЕВАТЬ ОТРИЦАЛЬТНОЕ ЗАНЧЕНИе
    OFFLINE,    // по умолчанию присваевается 0
    ONLINE,     // дефолт 1
    AWAY,       // дефолт 2
    DND,        // дефолт 3  главное очередность
    HOVER = 6,  // так же можно присваивать свое значение
    NEXTENUM      // значение будет больше на 1 чем предыдущее, т.е = 7;
};

int main() {

    int state = 0;

    //! для включения:
    state |= OUTLETS_FLOOR_1; // включение
    state |= BOILER;

    // получается что сейчас state включает в себя  OUTLETS_FLOOR_1 и BOILER

    if (state & BOILER){
        cout << "The Boiler on.\n";
    }
    if (state & OUTLETS_FLOOR_1){
        cout << "1 floor outlets on.\n ";
    }
    if (state & OVEN){
        cout << "Oven on\n";
    }

    //! для отключения:
    state &= ~OUTLETS_FLOOR_1;

    if (!(state&OUTLETS_FLOOR_1)) { // проверяем не включен ли

    cout << "First floor off.\n";
    }

    return 0;
}
