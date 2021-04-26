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

 /* Логика
  *
  *
  *
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
         int quantity = 0;             // кол-во жилиых домов на территории
         string name_build;             // предназначение дома дома
         int level = 0;                 //этажность !жилых! домов (может быть несколько!)
         vector<double> ceiling_height ; // высота потолков на каждом из этажей, кол-во элементов зависит от level.
         vector<int> rooms_level  ; // size = level, н - р [0] = 2; (Комнаты)
         vector<string> name_room; //size =  rooms_level [0]+[1]+[2] ...[N];
         vector<double> room_area ; // площадь комнат
         bool stove_heating = false; // будем считать что все жилые дома отапливаеются от центральной системы отопления
         int build_area = 1; // площадь постройки будет расчитываться по максимальному значению площадей помещения одного из этажа, чей больше..)
                                // из расчёта + 100 см на стены :D сильно не хочется заморачиваться


     };

     struct other_build { // остальные постойки (не жилые)
         string name;
         int level  = 0;                   //этажей я ограничил макс 2 этажа
         vector<int> room_level ; //комнат на этажах ограничил до 2
         double build_area = 0 ; // прощадь постройки.

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
                "Mud room\n"
                "Dance room\n";

        for(int i = 0; i < name_room.size() ; ++i){
            cout << "enter a name for the room №: " << i + 1;
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
        int length = 0;
        while (length < 1)cin >> length;
        cout << "Enter the width for '" << name_room[i] << "'\n";
        int width = 0;
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



    for (int count = 0; count < quantity; ++ count) {
        land.id = count + 1;
        cout << " How many buildings are there on the site in general? (min 1) for " << land.id << " plot\n";
        while (land.buildings < 1) cin >> land.buildings;

        cout << "How many of them are residential?";
        while (land.build.quantity < land.buildings && land.build.quantity < 1) cin >> land.build.quantity; //! не может ыть жилых домов меньше 1 и больше указанных всего)

        cout << "Okay! Will describe residential buildings first!\n";
        for(int i = 0 ; i < land.build.quantity ;++i){
            if (i == 0) {
                cout << "This is the master's house...\n";
                land.build.name_build = "Master's house";

                cout << "How many storeys is the building?\n"
                        "min 1, max 3 \n";
                while (land.build.level < 1 || land.build.level > 3) cin >> land.build.level;


                land.build.ceiling_height[land.build.level]; //высота потолков
                for (int k = 0; i < land.build.ceiling_height.size() ;++i){
                    cout << "On " << k + 1  << " Lvl. Ceiling height? ";
                    cin >> land.build.ceiling_height[k];
                }

                int sum_rooms_level = {};
                land.build.rooms_level[land.build.level];     // комнат на этаже
                for(int k = 0; k < land.build.rooms_level.size(); ++k){
                    cout << "On " << k + 1 << " Lvl. How many rooms?\n";
                    cin >> land.build.rooms_level[k];
                    sum_rooms_level += land.build.rooms_level[k];
                }

                land.build.name_room[sum_rooms_level]; // инициализируем размер  вектора  колличеством комнат
                names_rooms(land.build.name_room);  // присваиваем названия комнат

                land.build.room_area[sum_rooms_level]; // инициализация размера вектора площади каждой комнаты
                rooms_area(land.build.room_area, land.build.name_room); // инициализируем площадь комнат)

                cout << "And finally \n"
                        "Is your house heated by stove heating (yes or no)?\n";
                string answer;
                while (answer != "yes" && answer != "no") cin >> answer;

                if (answer == "yes") land.build.stove_heating = true;

                cout << "Good! Let's move on\n";


 //!!! добавь !площадь застрйки дома....




//! запишем главный дом в файл..._______________________________________________________________________________________________

                ofstream add_record_in_file ("..\\inventory.txt", ios::app);
                add_record_in_file << "Plot ID " <<  i + 1 << endl;
                add_record_in_file << "Name of the building " << land.build.name_build << endl;
                add_record_in_file << "Floors in the building " << land.build.level <<  endl;
                for (int k = 0; k < land.build.level; ++i ){
                    add_record_in_file << "Ceiling height on the " << i + 1 << " floor = "
                                        <<  land.build.ceiling_height[k] << endl;
                }
                for(int k = 0 ;k < land.build.rooms_level.size() ;++k) {
                    add_record_in_file << "On the " << k + 1 << " floor of rooms: " << land.build.rooms_level[k];

                }


         допиши код мудак



                add_record_in_file.close();


            }

            else if (i > 0){
                int answer = 777;
                cout << "Ok, who owns this living space? \n"
                        "Enter your answer \n"
                        "1 - guest room?\n"
                        "2 - servants ' home\n"
                        "3 - hotel?\n"
                        "4 - your own version?\n";
                while (answer < 0  || answer > 4) cin >> answer;

                if(answer == 1) land.build.name_build = "Guest room";
                else if(answer == 2) land.build.name_build = "Servants' home";
                else if(answer == 3) land.build.name_build = "Hotel";
                else {
                    getline(cin, land.build.name_build);
                }


            }
        }


    }




    return 0;
}
