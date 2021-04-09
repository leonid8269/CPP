#include <iostream>
#include <fstream>

int main() {
    std::ifstream bank;
    bank.open("C:\\CPP\\LearningProcess\\22\\2 reading different types of data\\bank.txt");

    int money;
    std::string currency;

    bank >> money >> currency; // первое число считывает
    std::cout << money << " " << currency << std::endl;

    bank >> money >> currency; //второе число
    std::cout << money << " " << currency;

    bank.close();
    return 0;
}
