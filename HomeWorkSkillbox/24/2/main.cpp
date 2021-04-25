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


 struct village{
 private:

     struct life_house{
         int quantity = 0;             // кол-во жилиых домов
         std::string name_build;        // имя дома
         int level = 0;        //этажность жилых домов (может быть несколько!)
         std::vector<double> ceiling_height ; // высота потолков на каждом из этажей, кол-во элементов зависит от level.
         std::vector<int> rooms_level ; // кол-во комнат на этаже. кол-во эл зависит от левел
         std::vector<std::string> name_room; //названия комнат, кол-во элементов зависит от  размера room slvl* на содержание..
         std::vector<double> room_area ; // кол-во эл от room lvl
         bool stove_heating = false;
     };

     struct other_build {
         std::vector<std::string> name; // построек может быть несколько... кол-во элементов зависит от количества простроек)
         int level  = 0;                   //этажей
         std::vector<int> room_level ; //комнат на этажах
         double build_area = 0 ; // прощадь постройки.

     };


 public:
     int id = {}; // номер участка
     int buildings = {}; //кол-во зданий на участке.

     life_house build; // структура в структуре
     other_build other;
 };


int main() {
    using namespace std;
    int quantity = {};
    cout << "Enter the total number of plots in the village. \n";
    while (quantity <= 0) cin >> quantity;

    village land;



    for (int count = 0; count < quantity; ++ count) {
        land.id = count + 1;
        cout << " How many buildings are there on the site in general? (min 1) for " << land.id << " plot\n";
        while (land.buildings < 1) cin >> land.buildings;

        cout << "How many of them are residential?";
        while (land.build.quantity < land.buildings && land.build.quantity < 1) cin >> land.build.quantity;

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

                land.build.rooms_level[land.build.level];     // комнат на этаже
                for(int k = 0; k < land.build.rooms_level.size(); ++k){
                    cout << "On " << k + 1 << " Lvl. How many rooms&\n";
                    cin >> land.build.rooms_level[k];
                }

                //!!площадь комнат?___________________________________________________________________________


                cout << ""



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
