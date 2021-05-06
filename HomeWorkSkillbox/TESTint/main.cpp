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
    for (int i = 0; i < 5 ;++i){
        std::string name;
        std::cin >> name;
        maps.insert(std::make_pair(name + std::to_string(i), name ));
    }

    for (auto it = maps.begin();
            it!=maps.end();++it){
        std::cout << it->second << std::endl;
    }


    return 0;

}
