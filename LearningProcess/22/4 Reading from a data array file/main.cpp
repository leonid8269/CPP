#include <iostream>
#include <fstream>


int main() {
    using namespace std;
    double purse[4];

    ifstream bank;
    bank.open("C:\\CPP\\LearningProcess\\22\\4 Reading from a data array file\\bank.txt");
    for (int i = 0; i < 4  ; ++i)bank >> purse[i];
    for (int i = 0; i < 4; ++i ) cout << purse[i] << " ";


    bank.close();



    return 0;
}
