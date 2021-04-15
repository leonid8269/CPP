#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>



int main() {
    using namespace std;

    string path = "C:\\CPP\\HomeWorkSkillbox\\22\\2\\text.txt";
    ifstream text;
    text.open(path, ifstream::binary);
    if (!text.is_open()) cout << "Error opening file \n\a";
    else {
        while (!text.eof()){
           char works [20];
           text.read(works, sizeof(works));
           for (int i = 0; i < sizeof(works) ;++i) cout << works[i];
        }
    }
    text.close();




    return 0;
}
