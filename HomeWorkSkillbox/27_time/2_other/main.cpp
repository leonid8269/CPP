#include <iostream>
#include <ctime>
#include <map>
#include <iomanip>
#include <string>

#define KEY std::to_string(t_tm.tm_mon + 1) + std::to_string(t_tm.tm_mday)
#define FIND std::to_string(t_tm.tm_mon + 1) + std::to_string(t_tm.tm_mday)


int main() {
    std::map<std::string, std::string> map;
    do{
        std::cout << "Enter end or name\n";
        std::string ans;
        std::cin >> ans;
        if (ans == "end") break;
        else {
            time_t t = time(nullptr);
            tm t_tm = *std::localtime(&t);

            std::cout << "When your friend has a birthday? Enter in format YYYY/MM/DD\n";
            std::cin >> std::get_time(&t_tm, "%Y/%m/%d");
            map.insert(std::make_pair( KEY, ans));
        }
    }while (true);

    time_t t = time(nullptr);
    tm t_tm = *std::localtime(&t);



    for(auto it = map.find(FIND) ; it != map.end(); ++it){
        std::cout << it->first << " " << it->second << std::endl;
    }

    return 0;
}
