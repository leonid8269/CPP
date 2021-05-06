#include <iostream>
#include <map>
#include <string>


int main() {

    std::map<int,std::string> regist;

    int count = 0;
    int i = 0;
    do {
        std::string ans;
        std::cout << "Enter next or lastname the patient\n";
        std::cin >> ans;
        if (ans == "next") {
            for (std::map<int,std::string>::iterator it = regist.begin();
                    it != regist.end(); it ++){

            }
        }
        else {
            ++count;
            regist.insert(std::make_pair(i, ans));
        }
    }while (i < count);




    return 0;
}
