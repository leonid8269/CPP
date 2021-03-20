#include <iostream>
#include <sstream>
#include <string>

using namespace std;
/*
 * Из целой и дробной частей числа,которые в отдельности вводит пользователь
 * надо составить новое число с плавающей точкой (типа double) и вывести это
 * число обратно в консоль, для проверки. Целая часть - это та, часть числа,
 * которая находится до точки (запятой), дробная - после.
 * */


double result (const string& whole, const string& mantissa ){
    stringstream buf;
    buf << whole << "." << mantissa;
    double number = stod(buf.str());
    return number;
}


bool chek (const string& number){
    for (int i = 0 ; i < number.length(); ++i)
        return (number[i] >= '0' && number[i] <= '9') ;
}


void initialization (string& number, bool turn ){
    do{
        turn ? cout << "Enter the value of the whole part:\n" : cout << "And and fractional part\n";
        cin >> number;

    }while (!chek(number));
}

int main() {
    string whole, mantissa;

    initialization(whole,true);
    initialization(mantissa, false);    // где true - целая часть, false - мантисса.

    cout << result(whole,mantissa);

    return 0;
}
