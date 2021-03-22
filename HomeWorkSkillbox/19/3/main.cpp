#include <iostream>
#include <string>

using namespace std;


bool checkPoint(const string& num, int beginning, int border){

    int point = 0;
    for (int i = beginning; i < border; ++i){
        if (num[i] == '.') ++point;
        if (point > 1) return false;
    }
    return true;
}

bool chekString (const string& num, int rowSeparator){
    int matches = 0;
    for (int i = 0; i < num.length(); ++i){
        if (num[i] < '*' || num[i] == ',' || num[i] > '9' ) return false;       //! таблица ASCII впомощь ;)

        if (num[i] == '/' || num[i] == '*' || num[i] == '-' || num[i] == '+'){
            ++ matches;
            rowSeparator = i;
        }
    }

    if (matches == 0 || matches > 1) return false;

    if (!checkPoint(num, 0, rowSeparator )) return false;                 //! Где 2 аргумент - с какого места начнется проверка. 3 аргумент - до какого
    if (!checkPoint(num, rowSeparator + 1, num.length())) return false;   //! + 1 - начало проверки после разделителя


    return true;
}

void calculationProcess (const string& str, int half){

    double first;
    double second;



}


int main() {
    string calculator;
    int action = 0; // действие осуществляемое над числами

    do {
        cin >> calculator;
    }while (!chekString(calculator, action));

    calculationProcess(calculator, action);


    return 0;
}
