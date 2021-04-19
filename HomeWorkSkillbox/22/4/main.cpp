#include <iostream>
#include <fstream>
#include <string>



int main() {
    using namespace std;

    ifstream checkFile;
    string path = "..\\png.png";
    if  (path.substr(path.length() - 4) != ".png") {
        cout << "File extension error\n\a";
        return 1;
    }

    checkFile.open(path,ifstream::binary);
    if (!checkFile.is_open()) cout << "ERROR opening file \n\a";

    else {
        checkFile.seekg(1);
        char exp[3];
        checkFile >> exp;
        string a = exp;
        if (a == "PNG")
            cout << "This file is a PNG\n";
        else cout << "NO!\a\n";
     }
    checkFile.close();

    return 0;
}
