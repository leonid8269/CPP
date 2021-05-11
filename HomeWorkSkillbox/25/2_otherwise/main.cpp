#include <iostream>
#include <map>


int main() {
    std::map<std::string, int8_t> reg;

    std::string command;
    for (int i = 0, count = 1; i < count; ++i ){
        std::cout << "Enter command (last name or next)\n";
        std::cin >> command;
        if (command == "next" ){
            std::cout << reg.begin()->first << '\n';
            reg.begin()->second --;
            if(reg.begin()->second == 0) {
                std::cout << "Patients with the surname " << command << " ended\n";
                reg.erase(reg.begin());
            }
        }else {
            auto nameSeek = reg.find(command);
            if(nameSeek->first == command){
                nameSeek->second ++;
                std::cout << "Successfully added single-fampots\n";
            }else {
                std::cout << "The surname is not found add to the queue!\n";
                reg.insert(std::make_pair(command, 1));
            }
            count += 2;
        }
    }

    return 0;
}
