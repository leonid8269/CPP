#include <iostream>
#include <string>

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




void temporaryPath (string& indication){
    for (int day = 0; day < 2; ++ day  ){
        cout << "Day " << day + 1 << endl;  // +1 потому что люди считают от 1 =D

        for (int hour = 0 ; hour < 24 ; ++ hour ){
            //нужно дедлелать косяк со вренинем чтобы было 00:00 а не 0:00
            //и цикл от
            cout << "Now " << hour << ":00" << "Enter the temperature testimony outside, temperature inside, "
                                               "is there a movement outside, whether the light is included in the house:\n";
            cout << "In format: <numbers> <numbers> <yes/no> <on/off>  \n";
            getline(cin, indication);
            // здесь будет функция парсинга строки... и дальнейшего выполнения программы

        }

    }

}


int main() {
    string indications; //! в эту стоку вводим





    return 0;
}
