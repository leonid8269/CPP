#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>



int main() {
    using namespace std;

    ifstream text;
    text.open("C:\\CPP\\HomeWorkSkillbox\\22\\1\\text.txt",ifstream::binary);
    if (!text.is_open()) cout << "Error opening file \n\a";
    else {
        while (!text.is_open()){

        }
    }
    text.close();




    return 0;
}
