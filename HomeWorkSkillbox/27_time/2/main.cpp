#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <fstream>

enum {
    YEAR,
    MONTH,
    DAY
};

struct friends{
    std::string name;
    int YMD[3]{};
};

void load (std::vector<friends>& fri){ // Для удобства проверки.
    std::ifstream file ("..\\load.txt");
    if (!file.is_open()) std::cout << "ERROR opening file\n\a";
    else{
        uint8_t priority = 0;
        while (file.eof()){
            fri.emplace_back();
            file >> fri[priority].name >> fri[priority].YMD[YEAR] >> fri[priority].YMD[MONTH] >> fri[priority].YMD[DAY];
            priority ++;
        }
    }
    file.close();

}

int main() {
    std::vector<friends> fri(0);
    uint8_t priority = 0;

    std::string ans;
    do {
        std::cout << "Enter \"end\" or name\n";
        std::cin >> ans;
        if (ans == "end") break;
        else if ( ans == "load" && !priority){ //пиши свой список друзей или воспользуйся моим :D
            load(fri);
        }
        else {

            fri.emplace_back();
            fri[priority].name = ans;
            std::cout << "Enter the date of birth YYYY MM DD\n";
            std::cin >> fri[priority].YMD[YEAR];
            std::cin >> fri[priority].YMD[MONTH];
            std::cin >> fri[priority].YMD[DAY];
        }
    }while (true);

    time_t t = time(nullptr);
    std::tm local = *std::localtime(&t);


    for (int i = 0; i < fri.size() ; ++i){
        if ((fri[i].YMD[DAY] == local.tm_mday) &&  (fri[i].YMD[MONTH] == (local.tm_mon + 1)) )
            std::cout << "Today is the birthday of " << fri[i].name;

        else if ( ){

        }
    }


    return 0;
}
