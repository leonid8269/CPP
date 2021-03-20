#include <iostream>
#include <climits>

using namespace std;


bool compare (double value, double reference, double epsilon){
    return (value >= reference - epsilon) && (value <= reference + epsilon);
}
int main() {

    /* тип данных |  размер в байтах | Диапазон значений
     *  bool            1                   TRUE FALSE
     *  char            1                   1 - 255
     *  int             4                   -2147483648 +2147483647 или  INT_MIN  INT_MAX
     *  float           4                   1.175494351 E - 38 ДО 3.402823466 E + 38
     *  double          8                   2.2250738585072014 E - 308 до 1.7976931348623158 E + 308
     *
     *
     *
     * откуда взялся такой диопазон у инт?
     * 1 байт = может принимать 256 значений
     * 4 байта = может принимать 4 294 967 296 различных комбинаций
     * делим это число на два и получаем 2 147 483 648
     * получаем +диопазон инта
     *
     *запоминать не обязательно есть заголовочный файл climits
     *
     *
     *
     *
     * */


    cout << "Min: " << INT_MIN << " Max: " << INT_MAX << endl;


    //________________________

    double reference = 36.6;
    double min = reference - 0.5;
    double max = reference + 0.5;
    double temperature = 36.8;
    bool in_range = temperature >= min && temperature <= max; // все это запишем проще в функцию.

    cout << in_range << endl;
    cout << compare(temperature, min, max)<< endl;      // функция возвращает если диопазон тепмературы не нарушен



    if (0.1 + 0.1 + 0.1 != 0.3){
        cout << "The inscription must be absent \n"; // эта надпись должна отсутствовать..
                                                        // но она есть потому что компьютер тупой..
                                                        // нужно прибегнуть к функции которую мы написали
    }
    if (!compare(0.1 + 0.1 + 0.1, 0.3, 0.001)){
        cout << "There is no inscription here\n";  //  теперь все ок.
    }


                                 //!!!!!!!!!!!!!!!!!!!!! float опасный тип данных с ним аккуратно!
                                 //!? что такое детерминированны



    return 0;
}
