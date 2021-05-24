#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

#define MDAY (friends[i].data.tm_mon * 30) + friends[i].data.tm_mday
#define CHECK_1 (friends[i].data.tm_mon == today.tm_mon && friends[i].data.tm_mday > today.tm_mday) || \
                    friends[i].data.tm_mon > today.tm_mon

#define TODAY_BIRTHDAY friends[i].data.tm_mon == today.tm_mon && friends[i].data.tm_mday == today.tm_mday
#define YEARS   today.tm_year - friends[i].data.tm_year

struct birthday{
    std::string name;
    tm data{};
};



int main() {
    std::vector<birthday> friends;
    uint8_t priority = 0;
    std::string answer;

    do {
        std::cout << "Enter end or name\n";
        std::cin >> answer;
        if (answer == "end") break;
        else {
            friends.emplace_back();
            friends[priority].name = answer;
            std::cout << "Enter the driving date in YYYY/MM/DD format\n";

            time_t t = time(nullptr);
            friends[priority].data = *std::localtime(&t);
            std::cin >> std::get_time(&friends[priority].data, "%Y/%m/%d");
            ++priority;
        }
    }while (true);

    time_t t = time(nullptr);
    std::tm today = *std::localtime(&t);

    uint8_t minDay = UINT8_MAX;
    for (uint8_t i = 0; i < friends.size(); ++i){
        if (TODAY_BIRTHDAY){
            std::cout << "Today is the birthday \"" << friends[i].name << "\"\n";
            std::cout << "He will be " << YEARS << " years old\n";
        }else if (CHECK_1){
            minDay = MDAY;
        }
    }

    for (uint8_t i = 0 ; i < friends.size() ; ++i){
        if (MDAY == minDay) {
            std::cout << "Nearest birthday with " << friends[i].name;
            std::cout << "He will be " << YEARS << " years old\n";
            break;
        }
    }

    return 0;
}
