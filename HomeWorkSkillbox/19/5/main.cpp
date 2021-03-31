#include <iostream>
#include <string>
#include <sstream>
#include "windows.h"
#include <ctime>

using namespace std;

enum shield{
    POWER_HOUSE = 1,        //!ВКЛ/ВЫКЛ эл. энергия
    SOCKETS = 2,            //!Розетки
    LIGHT_HOUSE = 4,        //!Свет в доме
    LIGHT_STREET = 8,       //!Свет улица
    HEAT_HOUSE = 16,         //!Свет дома
    HEAT_WATER_WELL = 32,    //!отопление трубопровода
    AIR_COOL = 64            //!кондиционер
};

void timeInitialization(string &day, string &month, string &numMonth, int &hour, int &minute) {

    time_t rawtime; // скрока в секундах
    time ( & rawtime );

    stringstream time;
    time << ctime (&rawtime);

    char ignore; // не знал как пропустить : в строке времени.
    time >> day >> month >> numMonth >> hour >> ignore >> minute;

    time.str(" ") ;// очистка строки буфера
    time.clear();   //сброс флагов ошибок (нужно почитать что это)
}

void dataCollection (int hour, int minute, double temperatureOutside,
                     double temperatureInside,string& movingOutside,
                     string& powerLight){ // в данной функции будет проводится сбор информации с датчиков.

    for (int day = 0; day < 2  ;++day){
        for (int step = 0;step < 24 ; ++step, ++hour){
            if (hour == 24) hour = 0;
            string zero;
            if (hour < 10) zero = "0";
            cout << "Status on  " << zero <<hour << ":" << minute << ".\n";


        }
    }



}

int main() {
    string day, month, numMonth;
    int hour, minute;


    timeInitialization(day, month, numMonth, hour, minute);

    int statusSystem = 0;
    string zero;
    if (minute < 10) zero = "0"; // чтобы небыло 20:6, а было 20:06

    cout << "Hello, today is " <<  day << " the " << numMonth << "th. \n"
            "Now is the time: " << hour << ":"  << zero << minute << ".\n"
            "I am beta-version home caregiver!\n"
            "I will keep an eye on the climate and the comfort of the house. \n"
            "Have a nice weekend break\n"
            "I will be with you for exactly two days and every hour I will update the sensors\n"
            "To start the system working turn on the main switch\n"
            "Enter in the console: ON\n";

    string toStart;
    do{
     cin >> toStart;
    }while (toStart != "ON");
    cout << "Starting the system. Please wait...";

    Sleep(3000);
    statusSystem |= POWER_HOUSE;
    cout << "\nThank you for waiting...\n";
    cout << "Have a good two days!!\n";

    double temperatureOutside = 0, temperatureInside = 0;
    string movingOutside, powerLight;

    dataCollection (hour, minute, temperatureOutside, temperatureInside,
                    movingOutside, powerLight);




    return 0;
}
