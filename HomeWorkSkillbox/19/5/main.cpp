#include <iostream>
#include <string>
#include <sstream>

using namespace std;

enum shield{
    POWER_HOUSE,        //!ВКЛ\ВЫКЛ эл. энергия
    SOCKETS,            //!Розетки
    LIGHT_HOUSE,        //!Свет в доме
    LIGHT_STREET,       //!Свет улица
    HEAT_HOUSE,         //!Свет дома
    HEAT_WATER_WELL,    //!отопление трубопровода
    AIR_COOL            //!кондиционер
};

void powered_heat_water_well(){



}


void parsingIndication(stringstream& source){

    double temperatureOutside = 0;
    double temperatureInside = 0;
    string movementOutside;
    string powerLight;

    source >> temperatureOutside >> temperatureInside >> movementOutside >> powerLight;

    // выполнение программы умного дома...


}


void temporaryPath (){
    for (int day = 0; day < 2; ++ day  ) {
        cout << "Day " << day + 1 << endl;  // +1 потому что люди считают от 1 =D

        for (int hour = 0; hour < 24; ++hour) {
            cout << "Now " << hour << ":00 " << "Enter the temperature testimony outside, temperature inside, "
                                                "is there a movement outside, \nwhether the light is included in the house:\n";
            cout << "In format: <numbers> <numbers> <yes/no> <on/off>  \n";

            string buf;
            getline(cin, buf);      //инициализация датчиков

            stringstream indication;
            indication << buf;
            buf.clear();                // очистка вводимой строки
            parsingIndication(indication);
            indication.str("");     // очистка буфера стрингстрим
        }
    }
}


int main() {

    temporaryPath();




    return 0;
}
