#include <iostream>
#include <fstream>

std::string valText (){
    using namespace std;
    string name = "";

    bool good = false;
    while (!good){
        cin >> name;
        for (int i = 0; i < name.length(); ++i)
            if ((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z')) {
                cout << "Try Again\a\n";
                break;
            }else good = true;
    }
    return name;
}

int money(){
    using namespace std;
    string cash;
    while (true){
        cash = ""; //description of the line content
        cin >> cash;
        bool stepDown = false;  // flag for returning to the beginning of the cycle
        for(int i = 0; i < cash.length() ; ++i){
            if (cash[i] < '0' || cash[i] > '9') {
                stepDown = true;
                cout << "Try Again\a\n";
                break;
            }
        }
        if(stepDown) continue;  //if the check failed we return to the beginning of the loop
        else break;
    }

    return  stoi(cash);
}

std::string date (){
    using namespace std;
    string number;

    while (true) {
        cin >> number;
        if (number.length() != 10){
            cout << "Try again\a\n";
            continue;
        }

        int day = stoi(number.substr(0, 2));
        int month = stoi(number.substr(3, 4));
        int year = stoi(number.substr(6, 9));

        if ((day < 1 || day > 31) || (month < 1 || month > 12) || (year < 0 || year > 2022)) {
            cout << "Try again!\n\a";
            continue;
        }
        break;
    }
    return number;
}


int main() {
    using namespace std;
    ofstream book("..\\accounting_book.txt", ios::app);
    for (int i = 0; i < 3; ++i){ // вносить данные 3-х человек
        cout << "Enter a name of the person:\n";
        book << valText() << " ";

        cout << "Enter a lastname of the person:\n";
        book << valText() << " ";

        cout << "Money issued:\n";
        book << money() << " ";

        cout << "Enter the date of issue of the salary in the format DD.MM.YYYY!\n";
        book << date() << " ";

        book << endl;
    }
    book.close();


    return 0;
}
