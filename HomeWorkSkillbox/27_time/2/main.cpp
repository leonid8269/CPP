#include <iostream>
#include <ctime>
#include <iomanip>
#include <map>
#include <vector>

//Первая мысль которая возникает, программа для пользования на каждый
// день. зашел - посмотрел вышел. значит, смысла нет не вписывать даты до сегодняшнего дня (ведь по условию их
// показывать не надо. значить иначе с эти бороться буду)
//


int main() {
    std::map<time_t, std::string> map;
    std::string ans;
    while (true){
        std::cout << "Enter end or name friend\n";
        std::cin >> ans;
        if (ans == "end") break;
        else {
            std::cout << "Enter birthday friend\n";


        }
    }

    //map.insert(std::make_pair(time(nullptr),"Today")); // добавил сегодняшний день

    auto it = map.begin();
    std::tm* lolka = std::localtime(&it->first);
    std::cout << lolka->tm_mday;


    return 0;
}
