#include <iostream>
#include <ctime>
#include <iomanip>


int main() {
    std::time_t t = std::time(nullptr);
    std::tm local = *std::localtime(&t);
    std::cin >> std::get_time(&local, "%H:%M");
    std::cout << std::asctime(&local) << "\n";
    return 0;
}
