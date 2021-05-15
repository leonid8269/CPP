#include <iostream>
#include <iomanip>
#include <ctime>

int main() {
    time_t t = std::time(nullptr);
    int foo;
    std::cin >> foo;
    std::time_t d = std::time(nullptr);

    double a = std::difftime(t, d);
    std::time_t f = d + (std::time_t)a;

    std::tm* local_future = std::localtime(&f);
    std::cout << asctime(local_future) << "\n";

    local_future->tm_sec += 12; //говорится о НЕпростоте правки, так как нельзя же чтобы был -1 день...



    return 0;
}
