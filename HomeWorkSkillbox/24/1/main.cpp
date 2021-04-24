#include <iostream>
#include <fstream>

struct data{

    std::string name;
    std::string date;
    int salary;
};

void readFile(std::ifstream& file, data& reading){
    std::cout << "Enter a name: \n";

    std::getline(std::cin, reading.name);
    std::cout << "Enter date: (without spaces) \n";
    std::cin >> reading.date;
    std::cout << "Enter size salary: \n";
    std::cin >> reading.salary;

    file.read((char*)reading.name.length(), sizeof reading.name.length());
    file.read((char*)reading.date.length(), sizeof reading.date.length());
    file.read((char*)&reading.salary, sizeof reading.salary);
    file << std::endl;
}

void writeFile(std::ofstream& file, data& record){


}

int main() {
    data journal;
    using namespace std;
    cout << "What operation should I perform (add of list)?\n";
    string answer;
    while (true) {
        cin >> answer;
        if ( answer != "add" && answer != "list") {
            cout << "Try again!\a\n";
            continue;
        } break;
    }

    if (answer == "add") {
        ofstream file ("..\\journal.bin", ios::binary);
        writeFile(file, journal);
        file.close();

    }else {
        ifstream file ("..\\journal.bin", ios::binary);
        readFile(file, journal);
        file.close();
    }

    return 0;
}
