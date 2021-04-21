#include <iostream>
#include <fstream>
#include <cstring>

int main() {
    using namespace std;
    /*
    int number;
    cin >> number;

    ofstream file("..\\file.bin", ios::binary);
    if (!file.is_open()) cout << "Error opening file!\n\a";
    else {

        file.write((char*)& number ,sizeof(number));

    }
    file.close();
    */


    char* title = "Skillbox";
    ofstream file ("..\\title.bin", ios::binary);
    file.write(title, std::strlen(title)) ; //strlen возвращает длину нультерминированный сторки



    file.close();



    return 0;
}
