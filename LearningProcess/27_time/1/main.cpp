#include <iostream>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));

   // std::cout << std::time(nullptr); // вывод времени в секундах
    time_t a = std::time(nullptr);
    std::tm* local = std::localtime(&a);
    //std::cout << local->tm_hour << '\n'; // вывести только часы
    std::cout << asctime(local); // вывести дату полностью

    return 0;
}
