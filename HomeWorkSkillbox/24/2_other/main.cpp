#include <iostream>
#include <vector>
#include <string>
#include "windows.h"
#include <ctime>


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

enum rooms{
    bedroom = 1,
    kitchen,
    bathroom,
    children_room,
    living_room
};

enum other_facilities{
    garage = 1,
    shed,
    sauna
};

struct life_house{
    int level = 0; // от 1 до 3 этажей
    vector<int> ceiling_height; // на каждом из этажей. size - level
    vector<int> room_in_level;  // 2-4 комнаты на этаж. size - level
    vector<string> rooms_type;
    vector<int> rooms_area; // площадь комнат. size = room.type.size()
    int square{}; // площадь постройки
    bool stove_heating{};
};

struct other_builds{
    string type;
    int square{}; // площадь постройки
    bool stove_heating{};
};

void start_program(){
    cout << "Welcome to the village constructor\n"
            "Please wait for the download to start!\n";
    srand(time(nullptr));

    cout << '\t';
    char load = '#';
    for (int i = 0; i < 40; ++i){
        Sleep(rand() % 150 + 20);
        cout << load ;
    }
    cout << endl;
}

int square_build(vector<life_house>& apartment, int i){

    int max = 0;
    for (int j = 0; j < apartment[i].room_in_level.size(); ++j){ // size = level.
        int sum = 0;
        for (int k = 0; k < apartment[i].room_in_level[j]; ++k){ // н-р тут 3 комнаты
           sum +=  apartment[i].rooms_area[k];
        }
        if (sum > max ) max = sum;
    }

    int square = 0;
    while (true) {
        cout << "The area of the house can not be less than the maximum floor area\n"
                "Min = " << max << endl;
        cout << "Enter square this build\n";
        cin >> square;
        if (square < max ) {
            continue;
        }
        break;
    }

    return square;
}

int square_rooms (){
    int length{};
    cout << "Enter length a room (in centimeters )\n";
    while (length < 1) cin >> length;

    int width{};
    cout << "Enter width a room (in centimeters)\n";
    while (width < 1) cin >> width;

    return length * width;
}

void initialization_life_room(vector<life_house>& apartment, int i) { // комнаты в жилом доме

    for (int j = 0; j < apartment[i].level; ++j) {  // инициализация комнат на каждом из этажей
        cout << "Ceiling height (in centimeters) of the " << j + 1 << " floor\n";
        int ceiling{};
        while (ceiling <= 0) cin >> ceiling;
        apartment[i].ceiling_height.emplace_back(ceiling); // инициализация высоты потолка.

        cout << "On the " << j + 1 << " floor of rooms\n";
        int rooms{};
        while (rooms < 2 || rooms > 4) cin >> rooms;
        apartment[i].room_in_level.emplace_back(rooms);
    }

    for (int k = 0; k < apartment[i].room_in_level.size(); ++k){ // нулевая итерация = кол-во конмат на этаже
        for (int h = 0; h < apartment[i].room_in_level[k]; ++h){ //нулевая итерация = название первой комнаты
            cout << "Room number: " << h + 1 << " on the " << k + 1 << " floor\n";

            cout << "Choose what type of room this room belongs to:\n"
                    "Enter number\n"
                    "1 - Bedroom\n"
                    "2 - Kitchen\n"
                    "3 - Bathroom\n"
                    "4 - Children's Room\n"
                    "5 - Living room <3\n";
            int answer{};
            while (answer < 1  || answer > 5) cin >> answer;

            switch (answer) {
                case bedroom:
                    apartment[i].rooms_type.emplace_back("Bedroom");
                    apartment[i].rooms_area.emplace_back(square_rooms()); // площадь комнаты
                    break;

                case kitchen:
                    apartment[i].rooms_type.emplace_back("Kitchen");
                    apartment[i].rooms_area.emplace_back(square_rooms());
                    break;

                case bathroom:
                    apartment[i].rooms_type.emplace_back("Bathroom");
                    apartment[i].rooms_area.emplace_back(square_rooms());
                    break;

                case children_room:
                    apartment[i].rooms_type.emplace_back("Children's Room");
                    apartment[i].rooms_area.emplace_back(square_rooms());
                    break;

                case living_room:
                    apartment[i].rooms_type.emplace_back("Living Room");
                    apartment[i].rooms_area.emplace_back(square_rooms());
                    break;

                default:
                    break;
            }
        }
    }
}




int main() {
   // start_program();

    string name_village; // название деревни
    cout << "Enter the name a village\n";
    cin >> name_village;

    int sum_ground_area; // количетскво участков в деревне
    cout << "How many plots are there in the village?\n";
    cin >> sum_ground_area;

    vector<int>region (sum_ground_area); // size = участков в деревне, содержание кол-во построек..
    cout << "Let's start detailing the sections!\n";

    for (int count = 0; count < region.size(); ++count){
        cout << "Region number " << count + 1 << endl;
        cout << "How many buildings are there in total on this site:\n";
        while (region[count] < 1) cin >> region[count];

        cout << "Of these, residential?\n";
        int sum_life_house{};
        while(sum_life_house < 1 || sum_life_house > region[count]) cin >> sum_life_house;

        vector<life_house> apartment(sum_life_house); //size = кол-во жилых домов.

        for (int i = 0; i < apartment.size(); ++i){
            cout << "How many floors in " << i + 1 << " residential building??\n";
            while (apartment[i].level < 1 || apartment[i].level > 3) cin >> apartment[i].level; // этажность здания...

            initialization_life_room(apartment,i);
            apartment[i].square = square_build(apartment,i);

            cout << "The house is heated by a stove(y\\n)?\n";
            char answer = 0;
            while (answer != 'y' && answer != 'n')cin >> answer;

            if (answer == 'y') apartment[i].stove_heating = true;
            else apartment[i].stove_heating = false;
        }

        if (region[count] - sum_life_house > 0) {
            cout << "Remaining buildings = " << region[count] - sum_life_house;
            vector<other_builds> other(region[count] - sum_life_house);

            for (int i = 0; i < other.size(); ++i){
                cout << "Choose the type of building: \n"
                        "1 - Garage \n"
                        "2 - Shed \n"
                        "3 - Sauna \n";
                int answer {};
                while (answer > 0 && answer < 4)cin >> answer;

                switch (answer) {
                    case garage:
                        other[i].type = "Garage";
                        break;
                    case shed:
                        other[i].type = "Shed";
                        break;
                    case sauna:
                        other[i].type = "Sauna";
                        cout << "Does the sauna have a stove and a pipe(y\\n)?\n";
                        char ans = 0;
                        while (ans != 'y' && ans != 'n') cin >> ans;
                        if (ans == 'y') other[i].stove_heating = true;
                        else other[i].stove_heating = false;
                        break;
                }
            }
        }


    }


    return 0;
}
