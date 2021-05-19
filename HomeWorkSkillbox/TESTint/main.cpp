#include <iostream>
#include <cstdint>
#include <map>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

int main (){
    std::map <std::string, std::string> map;

    time_t t = time(nullptr);
    std::tm tm_t = *std::localtime(&t);

    map.insert(std::make_pair( std::to_string(tm_t.tm_mon = 5) + ":" +
                std::to_string(tm_t.tm_mday = 12), "Lolkaa"));

    map.insert(std::make_pair( std::to_string(tm_t.tm_mon = 5) + ":" +
                std::to_string(tm_t.tm_mday = 6), "lala"));


    for (auto it = map.begin(); it != map.end(); ++it) std::cout << it->first << std::endl;



    return 0;

}





