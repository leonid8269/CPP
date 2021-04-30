/*!
 *
 *
 *  помощью структур данных создайте подробную модель посёлка.

 Каждый из них имеет свой уникальный номер.

 минимум один жилой дом, но возможны и другие сооружения, такие как гараж, сарай (бытовка) и баня.
 Для каждого здания предусмотрена информация о площади, которую он занимает на участке.
 В жилом доме может быть 1–3 этажа. На каждом из этажей может быть 2–4 комнаты.
 Каждая комната при этом может быть разных типов: спальня, кухня, ванная, детская, гостиная.
 Для каждой комнаты предусмотрены данные о её площади.
 Для каждого этажа также есть данные о высоте потолка.
 В жилом доме и бане может быть печь с трубой, информация об этом также должна быть предусмотрена в данных.

 Для всех упомянутых сущностей надо объявить соответствующие структуры данных.

 Вначале работы программы пользователь заполняет данные о посёлке: вводит общее количество участков
 и далее начинает детализировать каждый из участков.

 Для каждого участка сначала заполняется общее количество построек, а затем детализируется каждая постройка, этажи, комнаты на этажах.

 По итогам введённых данных вы можете рассчитать некий суммарный параметр, например, процент земли, занимаемой постройками,
 к общей площади всего посёлка.

 Главное в этой задаче не сама операция подсчёта, а структуры данных.


 */



#include <iostream>
#include <vector>
#include <fstream>


using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::vector;


 struct village{
     struct life_house{
         int quantity = 0;             // кол-во жил зданий
         string name_build;             // предназначение дома дома
         int level = 0;                 //этажность !жилых! домов (может быть несколько!)
         vector<double> ceiling_height ;// высота потолков на каждом из этажей, кол-во элементов зависит от level.
         vector<int> rooms_level  ; // size = level, н - р [0] = 2; (Комнаты)
         vector<string> name_room; //size =  rooms_level [0]+[1]+[2] ...[N];
         vector<double> room_area ; // площадь комнат
         bool stove_heating = false; // будем считать что все жилые дома отапливаеются от центральной системы отопления

     };

     struct other_build { // остальные постойки (не жилые)
         string name;
         int level  = 0;                   //этажей я ограничил макс 2 этажа
         vector<int> room_level ; //комнат на этажах ограничил до 2
     };

     int id = {}; // номер участка
     int buildings = {}; //кол-во зданий на участке.

     life_house build; // структура в структуре
     other_build other;
 };

void names_rooms(vector<string>& name_room){
    while (true){
        cout << "Standard names for rooms:\n"
                "Bedroom\n"
                "Living room\n"
                "Canteen\n"
                "Kitchen\n"
                "Hall\n"
                "Children's bedroom\n"
                "Bathroom\n"
                "Aquodiscoteca\n"
                "Mud_room\n"
                "Dance_room\n";

        for(int i = 0; i < name_room.size() ; ++i){
            cout << "Enter a name for the room ( without a space ) #: " << i + 1 <<  endl;
            cin >> name_room[i];
        }
        string answer;
        cout << "Are you sure about the room names (yes/no?)\n";
        while ( answer != "yes" && answer != "no") cin >> answer;
        if (answer == "yes") break;
        else continue;
    }

}

void  rooms_area (vector<double>& square, vector<string>& name_room ){
    cout << "Ok, let's start calculating the area of the rooms \n";

    for (int i = 0; i < square.size(); ++i){
        cout << "Enter the length for '" << name_room[i] << "'\n";
        double length = 0;
        while (length < 1) cin >> length;
        cout << "Enter the width for '" << name_room[i] << "'\n";

        double width = 0;
        while (width < 1) cin >> width;
        cout << "Room area = " << length * width << endl;
        square[i] = length * width;
    }
}


int main() {
    int quantity = {};
    cout << "Enter the total number of plots in the village. \n";
    while (quantity <= 0) cin >> quantity;


    village land;

    for (int count = 0; count < quantity; ++ count) {  // цикл проходит по всем постойкам на участке
        land.id = count + 1; //идентификатор участка
        cout << "How many buildings are there on the site in general? (min 1) for " << land.id << " plot\n";
        while (land.buildings < 1) cin >> land.buildings;

        cout << "How many of them are residential (minimum 1  and no more " << land.buildings << "): " << endl;
        while (land.build.quantity < land.buildings && land.build.quantity < 1) cin >> land.build.quantity; //! не может ыть жилых домов меньше 1 и больше указанных всего)

        cout << "Okay! Will describe residential buildings first!\n";

        for(int i = 0 ; i < land.build.quantity ;++i){
            if (i <= land.build.quantity ) {

                if ( i == 0) { // первый описоваемый дом - собственников
                    cout << "This is the master's house...\n";
                    land.build.name_build = "Master's house";
                }
                else {// далее (после первой итерации, если жилых домов больше 1)  уже предлагается выбрать смостоятельно
                    cout << "Purpose of the house (must be residential)\n"
                            "Enter the name of the house (destination):\n";
                    getline(cin, land.build.name_build);                // для чего\кого дом (обязательно жилой)
                }

                cout << "How many storeys is the building?\n" // этажность здания
                        "min 1, max 3 \n";
                while (land.build.level < 1 || land.build.level > 3) cin >> land.build.level;

                for (int a = 0; a < land.build.level; ++a) land.build.ceiling_height.emplace_back(0);
                //! дядьк не получается у меня размер задать по другому...
                //! думал так можно land.build.ceiling_height[land.build.level]
                //! а оказалось что нет, такой кастыль придумал


                for (int k = 0; k < land.build.ceiling_height.size() ;++k){
                    cout << "On " << k + 1  << " Lvl. Ceiling height? \n";
                    cin >> land.build.ceiling_height[k];
                }

                int sum_rooms_level = {};

                for (int a = 0; a < land.build.level; ++a)land.build.rooms_level.emplace_back(0);

                for(int k = 0; k < land.build.rooms_level.size(); ++k){
                    cout << "On " << k + 1 << " Lvl. How many rooms (min 2. max 4) ?\n";
                    while (land.build.rooms_level[k] < 2 || land.build.rooms_level[k] > 4)
                            cin >> land.build.rooms_level[k];

                    sum_rooms_level += land.build.rooms_level[k];
                }


                for (int a = 0; a < sum_rooms_level; ++a) land.build.name_room.emplace_back("0");
                names_rooms(land.build.name_room);  // присваиваем названия комнат


                for (int a = 0; a < sum_rooms_level; ++a) land.build.room_area.emplace_back(0);
                rooms_area(land.build.room_area, land.build.name_room); // инициализируем площадь комнат)

                cout << "And finally \n"
                        "Is your house heated by stove heating (yes or no)?\n";
                string answer;
                while (answer != "yes" && answer != "no") cin >> answer;

                if (answer == "yes") land.build.stove_heating = true;

                cout << "Good! Let's move on\n";


                ofstream add ("..\\inventory.txt", ios::app);
                add << "Plot ID :" <<  land.id << endl; //идентификатор участка
                add << "Name of the building : \"" << land.build.name_build << "\" " << endl; //название строения
                add << "Floors in the building = " << land.build.level <<  endl;  //этажность здания


                for (int k = 0; k < land.build.level; ++k )
                    add << "Ceiling height on the " << k + 1 << " floor = " <<  land.build.ceiling_height[k] << endl; //высота потолков

                for(int k = 0 ;k < land.build.rooms_level.size() ;++k)
                    add << "On the " << k + 1 << " floor of rooms: " << land.build.rooms_level[k] <<
                    " name room: \"" << land.build.name_room[k] << "\" "<< endl; // площадь комнат с названиями

                if (land.build.stove_heating) add << "The house is a fire hazard, as it is heated by a stove\n\n\n";
                else add << "This house is fireproof\n\n\n";
                add.close();


            }

            else {
               if (i == land.build.quantity ) cout << "Let's start the inventory of non-residential buildings\n"; //!проверить работу а именно надпись должна выводится только когда жилые дома заканчиваются

               cout << "Purpose of non-residential buildings\n";
               getline(cin, land.other.name);

               cout << "How many floors does the building have (min 1, max 2) \n";
               while (land.other.level < 1 || land.other.level > 2) cin >> land.other.level;

               cout << "Ok, this house has " << land.other.level << " floor(s)\n ";

               cout << "Let's count the rooms\n";
               land.other.room_level[land.other.level];

               for (int a = 0; a < land.other.room_level.size() ;a++){
                   cout << "How many rooms on the"  <<  a + 1 << " floor (maximum 2)\n";
                   while (land.other.room_level[a] < 1 || land.other.room_level[a] > 2 ) cin >> land.other.room_level[a];
               }

               ofstream add("..\\inventory.txt", ios::app);

               add  << "Structure type: NON-residential building! \n"
                    << "Building name " << land.other.name <<  endl
                    << "Floors " << land.other.level << endl;

               for (int a = 0;a < land.other.room_level.size() ;++a) add << "On the" << a + 1 << "floor of rooms "
                                                                            << endl << endl << endl;

               add.close();

            }
        }




    }




    return 0;
}
