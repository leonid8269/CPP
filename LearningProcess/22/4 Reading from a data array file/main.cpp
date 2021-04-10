#include <iostream>
#include <fstream>
#include <vector>

int main() {
    using namespace std;
    double purse[100];

    ifstream bank;
    bank.open("C:\\CPP\\LearningProcess\\22\\4 Reading from a data array file\\bank.txt");
    int count = 0;
    while (!bank.eof()){
        bank >> purse[count];
        count += 1;
    }
    for (int i = 0; i < count; ++i ) cout << purse[i] << " ";

    bank.close();



    return 0;
}
