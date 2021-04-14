#include <iostream>
#include <fstream>


int main() {
    using namespace std;

    string path = "C:\\CPP\\HomeWorkSkillbox\\22\\3\\text.txt";
    ifstream text;
    text.open(path);
    if (!text.is_open()) cout << "Error Opening file\a\n";
    else {

        while (!text.eof()) {


        }


    }
    text.close();


    return 0;
}
