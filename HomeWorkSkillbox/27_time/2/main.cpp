#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>


enum {
    YEAR,
    MONTH,
    DAY,
    DAY_IN_YEAR
};

struct birthday{
    std::string name;
    uint8_t date[4]{};
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
            std::tm tm_t = *std::localtime(&t);
            std::cin >> std::get_time(&tm_t, "%Y/%m/%d");

            friends[priority].date[YEAR]  = tm_t.tm_year;
            friends[priority].date[MONTH] = tm_t.tm_mon;
            friends[priority].date[DAY]   = tm_t.tm_mday;
            friends[priority].date[DAY_IN_YEAR] = tm_t.tm_mon * 30 + tm_t.tm_mday;

            ++priority;
        }
    }while (true);


    //! время сейчас
    time_t t = time(nullptr);
    std::tm tm_t = *std::localtime(&t);


 //! Есть проблема,  нужна сортировка пузырьком по дням-месяцам рождениям! или другой вариант)
    for (int i = 0; i < friends.size(); ++i ) {
        if (tm_t.tm_mon == friends[i].date[MONTH] && tm_t.tm_mday == friends[i].date[DAY]) {
            std::cout << "Today is the birthday of " << friends[i].name << ".\nAnd it is executed "
                      << tm_t.tm_year - friends[i].date[YEAR] << " year\n\n";
        }
    }

    uint8_t minDay = UINT8_MAX;

    for (int j = 0; j < friends.size(); ++j) {
        if (friends[j].date[DAY_IN_YEAR] - tm_t.tm_yday < minDay){
            minDay = friends[j].date[DAY_IN_YEAR] - tm_t.tm_yday;
        }
    }

    for (int k = 0; k < friends.size(); ++k ) {
        if ( friends[k].date[DAY_IN_YEAR] == minDay)
            std::cout << "The nearest birthday of " << friends[k].name << ".\nAnd it is executed "
                      << tm_t.tm_year - friends[k].date[YEAR] <<" year\n\n";

    }

    return 0;
}
