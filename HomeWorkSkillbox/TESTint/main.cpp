#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>
#include <fstream>



int main() {
    using namespace std;

    string pathTxt = "C:\\CPP\\HomeWorkSkillbox\\TESTint\\file.txt";

    ifstream txt;
    txt.open(pathTxt);
    if (!txt.is_open()) cout << "Error opening file!\n\a";
    else {
       while (!txt.eof()){
           int relevant, buf, sum;
           string name, lastName, date;
           txt >> name;
           txt >> lastName;



       }
    }

    txt.close();

    return 0;
}
