#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>
#include <fstream>



int main() {
    using namespace std;

    string number = "25.12.2018";
    int day = stoi(number.substr(0,2));
    int month = stoi(number.substr(3,4));
    int year = stoi(number.substr(6,9));





    return 0;
}
