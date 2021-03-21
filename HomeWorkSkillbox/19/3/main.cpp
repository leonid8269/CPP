#include <iostream>

using namespace std;

bool chekString (const string& num, int& half){
    int matches = 0;
    for (int i = 0; i < num.length(); ++i){
        if (num[i] == '/' || num[i] == '*' || num[i] == '-' || num[i] == '+'){
            ++ matches;
            half = i;
        }
        if (num[i] < '0' || num[i] > '9' ) return false;
    }
    if (matches == 0 || matches > 1) return false;
    return true;
}


int main() {
    string calculator;
    int action = 0; // действие осуществляемое над числами

    do {
        cin >> calculator;
    }while (!chekString(calculator, action));



    return 0;
}
