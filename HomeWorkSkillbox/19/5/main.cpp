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
    LIGHT_GARDEN = 8,       //!Свет сад
    HEAT_HOUSE = 16,         //!Отопление дома
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


void accomplishment(double temperatureOutside,double temperatureInside,
                     string& movingOutside, string& powerLight,
                     int hour,  int& statusSystem, int& tempLight){ // выполнение основы программы...

    if (temperatureOutside < 0 && !(statusSystem & HEAT_WATER_WELL)) {
        statusSystem |= HEAT_WATER_WELL;
        cout << "The water pipe heating system is turned ON!\n";
    }else if (temperatureOutside >= 5 && (statusSystem & HEAT_WATER_WELL)){
        statusSystem &= ~ HEAT_WATER_WELL;
        cout << "The water supply heating system is turned OFF\n";
    }

    if (((hour >= 16 || hour <= 5) && movingOutside == "yes") && !(statusSystem & LIGHT_GARDEN)) {
        statusSystem |= LIGHT_GARDEN;
        cout << "Turning ON garden lighting\n";
    }else if (((hour < 16 && hour >= 5) && movingOutside == "no") && (statusSystem & LIGHT_GARDEN)) {
        statusSystem &= ~ LIGHT_GARDEN;
        cout << "Turning OFF garden lighting\n";
    }

    if ((temperatureInside < 22) && !(statusSystem & HEAT_HOUSE)){
        statusSystem |= HEAT_HOUSE;
        cout << "Heating in the house is ON\n";
    }else if (temperatureInside > 25 && (statusSystem & HEAT_HOUSE)){
        statusSystem &= ~ HEAT_HOUSE;
        cout << "Heating in the house is OFF\n";
    }

    if ((temperatureInside >= 30) && !(statusSystem & AIR_COOL)){
        statusSystem |= AIR_COOL;
        cout << "Air cool ON\n";
    }else if((temperatureInside <= 25) && (statusSystem & AIR_COOL)){
        statusSystem &= ~ AIR_COOL;
        cout << "Air cool OFF\n";
    }

    if (powerLight == "on"){
        statusSystem |= LIGHT_HOUSE;
    }else {
        statusSystem &= ~LIGHT_HOUSE;
    }

    if ((hour >= 16 && hour < 20) && (statusSystem & LIGHT_HOUSE)){
        tempLight = 2700;
    }else if ((hour < 16 || hour >= 20) && (statusSystem & LIGHT_HOUSE)) {
        tempLight = 5000;
    }
    if (statusSystem & LIGHT_HOUSE) cout << "Current color temperature " << tempLight << "K\n";


}

bool chekCurrentData(const string& movingOutside, const string& powerLight){
    return (movingOutside == "yes" || movingOutside == "no" && powerLight == "on" || powerLight == "off");
}

void dataCollection (int hour, int minute, double temperatureOutside,
                     double temperatureInside,string& movingOutside,
                     string& powerLight, int& statusSystem, int& tempLight){ // в данной функции будет проводится сбор информации с датчиков.

    for (int day = 0; day < 2  ;++day){
        for (int step = 0;step < 24 ; ++step, ++hour){
            if (hour == 24) hour = 0;
            string zero;
            if (minute < 10) zero = "0";
            cout << "Status on  "  << hour << ":" << zero << minute << ".\n";
            cout << "Enter <temperature outside> <temperature inside> <yes and no moving outside?> <off and on light?>\n";

            do {

                cin >> temperatureOutside >> temperatureInside >> movingOutside >> powerLight;
               if (chekCurrentData(movingOutside, powerLight)) break;
               else {
                   cout << "\aError, Please try again\n";
               }
            }while(true);
            accomplishment(temperatureOutside, temperatureInside, movingOutside,powerLight,
                           hour, statusSystem,  tempLight);
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
            "Now is the time: "  << hour << ":"  << zero << minute << ".\n"
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
    statusSystem |= SOCKETS; // розетки всегдла вкл, когда включается рубильник.

    cout << "\nThank you for waiting...\n";
    cout << "Have a good two days!!\n";

    double temperatureOutside = 0, temperatureInside = 0;
    string movingOutside, powerLight;
    int tempLight = 0;

    dataCollection (hour, minute, temperatureOutside, temperatureInside,
                    movingOutside, powerLight, statusSystem, tempLight);

    cout << "I hope your weekend was great!\n"
            "Time to say goodbye\n"
            "Come again\n"
            "Shutting down the work...";
    Sleep(3000);
    statusSystem = 0;
    return 0;
}
