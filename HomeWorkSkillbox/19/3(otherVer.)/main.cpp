#include <iostream>
#include <sstream>


using namespace std;


int main() {
    stringstream text;
    string str;
    cin >> str;
    text << str;

    double first;
    double second;
    char half;

    text >> first >> half >>  second;
    cout << first <<  " " << second;

    if (half == '*') cout << first * second;
    else if ( half == '+') cout << first + second;
    else if (half == '-') cout << first - second;
    else if (half == '/') cout << first / second;
    else cout << "Error\n";


    return 0;
}
