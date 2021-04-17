#include <iostream>
#include <fstream>


int main() {
    using namespace std;

    string path = "..\\text.txt";
    ifstream text;
    text.open(path);
    if (!text.is_open()) cout << "Error Opening file\a\n";
    else {
        int max = 0, sum = 0;
        string name, lastName;
        while (!text.eof()) {
            string date;
            int salary;
            string bufName;
            string bufLastName;


            text >> bufName >> bufLastName >> salary >> date;
            sum += salary;
            if (max < salary ) {
                max = salary;
                name = bufName;
                lastName = bufLastName;
            }
        }
        cout << "Sum of funds received: " << sum << endl;
        cout << "The highest amount received: " << name << " " << lastName << ". In size: " << max;
    }
    text.close();



    return 0;
}
