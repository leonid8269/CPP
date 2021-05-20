#include <iostream>
#include <cstdint>
#include <map>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

int main (){


    time_t t = time(nullptr);
    time_t s = time(nullptr);

    std::tm today = *std::localtime(&s);
    std::tm t_tm = *std::localtime(&t);

    std::cin >> std::get_time(&t_tm, "%Y/%m/%d");


    std::cout << "to = " << today.tm_yday << " be = " << t_tm.tm_yday;


    return 0;

}





