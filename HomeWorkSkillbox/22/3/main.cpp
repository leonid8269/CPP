#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>



int main() {
    using namespace std;
    string word;
    cout << "Enter the word:\n";
    cin >> word;

    ifstream text;
    text.open("C:\\CPP\\HomeWorkSkillbox\\22\\1\\text.txt");

    string buf; // в него будут записываться слова для дальнейшего сравнивания.
    int countWord = 0;
    if (!text.is_open())cout << "Error opening file!\n\a";
    else {
        while(!text.eof()){
            text >> buf;
            if (buf == word) ++countWord;
        }
    }
    text.close();

    cout << countWord;


    return 0;
}
