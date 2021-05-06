#include <iostream>
#include <map>


int main() {
    std::map<int, std::string> ok;
          
		 ^   ^        ^         ^
	     1   2        3         4
	 1 словарь
     2 "адрес в словаре"
     3 содержание словаря
	 4 имя словаря


    ok[1] = "Sidorov";
    ok[2] = "Putin";

    std::cout << ok[2] << std::endl;

    ok[2] = "kill";

    std::cout << ok[2];

    return 0;
}
