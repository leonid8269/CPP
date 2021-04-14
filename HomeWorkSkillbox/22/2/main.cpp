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
        int workLine = 0;
        cout << "By how many words per line to output the text?\n";
        cin >> workLine;
        while (!text.eof()){
            for (int i = 0; i < workLine; ++ i ){
                string buf;
                text >> buf;
                cout << buf <<  " ";
            }
            cout << endl;
        }
    }
    text.close();




    return 0;
}
