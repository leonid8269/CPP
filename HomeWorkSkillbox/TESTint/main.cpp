#include <iostream>
#include <cstdint>
#include <map>

int main(){
    std::map<std::string,int> reg;
    reg.insert(std::make_pair("bvanov", 1));
    reg.insert(std::make_pair("aaetrov", 1));
    auto nameseek = reg.find("bvanov");
    if (nameseek->first == "bvsdanov"){
        std::cout << "seeking\n";
    }


    return 0;
}

