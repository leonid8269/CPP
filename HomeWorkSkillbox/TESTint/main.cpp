#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>
#include <fstream>
#include <map>

struct bot{
    std::string name = "Mudak#";
    int health{};
    int armor{};
    int location{};
};


int main() {

  std::vector<bot> bots(5);

    for (int i = 1; i != bots.size(); ++i){
        bots[i].name += '0' + i;
        bots[i].health = 10*i;
        bots[i].armor = 5*i;
        bots[i].location = i;
    }


    for(int i = 0; i < bots.size(); ++i) {
        std::cout << bots[i].name << " " << bots[i].health << " " << bots[i].armor << " " << bots[i].location << std::endl;
    }
    std::cout << std::endl;


    bots.erase(bots.begin()+1);

    for(int i = 0; i < bots.size(); ++i) {
        std::cout << bots[i].name << " " << bots[i].health << " " << bots[i].armor << " " << bots[i].location << std::endl;
    }


    return 0;
}
