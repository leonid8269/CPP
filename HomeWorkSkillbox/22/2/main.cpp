#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>



int main() {
    using namespace std;

    string path = "C:\\CPP\\HomeWorkSkillbox\\22\\2\\text.txt";
    ifstream text;
    text.open(path);
    if (!text.is_open()) cout << "Error opening file \n\a";
    else {
        while (!text.eof()){
           char works [20] ;
            works[19] = 0;
           text.read(works, sizeof(works) - 1); // -1 для того чтобы записывалось до \0
               cout << works;
        }
    }
    text.close();




    return 0;
}
