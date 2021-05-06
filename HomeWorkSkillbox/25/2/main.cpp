#include <iostream>
#include <map>
#include <string>

int main() {

    std::map<std::string,std::string> regist;

    int count = 0;
    int i = 0;
    do {
        std::string ans;
        std::cout << "Enter next or lastname the patient\n";
        std::cin >> ans;
        if (ans == "next") {
            std::cout <<regist.begin()->second << std::endl;
            regist.erase(regist.begin());
        }
        else {
            count+= 2;
            regist.insert(std::make_pair(ans + std::to_string(i), ans));
        }
        i++;
    }while (i < count);

    return 0;
}
