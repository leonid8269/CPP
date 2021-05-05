#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>
#include <fstream>
#include <map>


int main() {
   std::map<std::string, std::string> maps;

    maps.insert(std::pair<std::string, std::string>("1", "1"));
    maps.insert(std::pair<std::string, std::string>("2", "2"));
    maps.insert(std::pair<std::string, std::string>("3", "3"));
    maps.insert(std::pair<std::string, std::string>("1", "1"));
    maps.insert(std::pair<std::string, std::string>("2", "2"));
    maps.insert(std::pair<std::string, std::string>("3", "3"));
    maps.insert(std::pair<std::string, std::string>("4", "4"));
    maps.insert(std::pair<std::string, std::string>("4", "4"));


    for (std::map<std::string,std::string>::iterator it = maps.begin();
            it != maps.end(); ++it){
        std::cout << it->first << " " << it->second << std::endl;
    }




    return 0;
}
