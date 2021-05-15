#include <iostream>
#include <ctime>
#include "iomanip" // манипулирование-настрйока ввода вывода


int main() {
    std::time_t t = std::time(nullptr);
    std::tm* local = std::localtime(&t);
    std::cout << std::put_time(local,"%Y.%m.%d") << '\n'; // y - выдаст последние 2 цифры года, Y фул цифры года


    return 0;
}
