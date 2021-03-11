#include <iostream>
#include <cmath>
#include <string>

using std::string;
using std::cout;
using std::cin;


string encryptCaesar  (string txt, int num){
    string outcome;

    if (num > 25 || num < -25) num %= 26;

    for (int i = 0; i < txt.length() ; ++i) {
        if (txt[i] >= 'A' && txt[i] <= 'Z'){                        // A - Z  big
            if (txt[i] + num > 'Z') outcome += 'A' + (num - ('Z' - txt[i]))  - 1;
            else if (txt[i] + num < 'A') outcome += 'Z' - (abs(num) - (txt[i] - 'A')) + 1;
            else outcome += txt[i] + num;
        }

        else if ( txt[i] >= 'a' && txt[i] <= 'z')  {                // a - z small
            if (txt[i] + num > 'z') outcome +=  'a' + (num - ('z' - txt[i])) - 1;
            else if (txt[i] + num < 'a') outcome += 'z' - (abs(num) - (txt[i] - 'a')) + 1;
            else outcome += txt[i] + num;
        }
        else {                                                      //space and another sign
            outcome += txt[i];
        }
    }
    return outcome;
}


string decryptCaesar(string a, int b){
    return encryptCaesar(a,-b);

}

int main (){
    for (int option = 100 ; option != 0 ; ) {

        cout << "1 - Coding text!\n";
        cout << "2 - Decoding text!\n";
        cout << "0 - EXIT program\n";
        cout << "Choose one of the options: ";
        cin >> option;

        if (option == 1) {
            string txt;
            int number;
            cout << "Enter text: " << std::endl;
            cin.ignore();
            getline(cin, txt);
            cout << "Enter number coding: " << std::endl;
            cin >> number;
            cout << encryptCaesar(txt, number) << std::endl << std::endl;

        } else if (option == 2) {
            string txt;
            int number;
            cout << "Enter cipher: " << std::endl;
            cin.ignore();
            getline(cin, txt);
            cout << "Enter number decoding: " << std::endl;
            cin >> number;
            cout << decryptCaesar(txt, number) << std::endl << std::endl;
        }
    }
    return 0;

}