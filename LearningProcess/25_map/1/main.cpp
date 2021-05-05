#include <iostream>
#include <map>


int main() {
    std::map<int, std::string> ok;
          ^   ^        ^
      словарь
              "адрес в словаре"
                        содержание словаря



    ok[1] = "Sidorov";
    ok[2] = "Putin";

    std::cout << ok[2] << std::endl;

    ok[2] = "kill";

    std::cout << ok[2];

    return 0;
}
