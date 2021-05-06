#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>
#include <fstream>
#include <map>



int main() {

    std::map<int, std::string> maps;
    maps.insert(std::pair<int,std::string>(1, "f"));
    maps.insert(std::pair<int,std::string>(2, "b"));
    maps.insert(std::pair<int,std::string>(3, "d"));
    maps.insert(std::pair<int,std::string>(4, "a"));
    maps.insert(std::pair<int,std::string>(5, "e"));
    maps.insert(std::pair<int,std::string>(6, "c"));

    for (std::map<int, std::string>::iterator it = maps.begin();
            it!=maps.end();++it){

    }


    return 0;

}
