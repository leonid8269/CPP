#include <iostream>
#include <regex>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::regex;
using std::regex_match;

string gameOver(string a){

    bool petya = false, vanya = false;
    string result_X, result_O;

    for (int i = 0 ; i < a.length() ; ++i){
        if ( !(a[i] == 'X' || a[i] == 'O' || a[i] == '.') ) return "Incorret";
        if (a[i] == 'X') result_X += std::to_string(i);
        if (a[i] == 'O') result_O += std::to_string(i);
    }


    auto optionOne = regex (".*012.*");
    if (regex_match (result_X,optionOne)) petya = true;
    if (regex_match (result_O,optionOne)) vanya = true;

    auto optionTwo = regex (".*345.*");
    if (regex_match (result_X,optionTwo)) petya = true;
    if (regex_match (result_O,optionTwo)) vanya = true;

    auto optionThree = regex (".*678.*");
    if (regex_match (result_X,optionThree)) petya = true;
    if (regex_match (result_O,optionThree)) vanya = true;

    auto optionFour = regex (".*036.*");
    if (regex_match (result_X,optionFour)) petya = true;
    if (regex_match (result_O,optionFour)) vanya = true;

    auto optionFive = regex (".*147.*");
    if (regex_match (result_X,optionFive)) petya = true;
    if (regex_match (result_O,optionFive)) vanya = true;

    auto optionSix = regex (".*258.*");
    if (regex_match (result_X,optionSix)) petya = true;
    if (regex_match (result_O,optionSix)) vanya = true;

    auto optionSeven = regex (".*246.*");
    if (regex_match (result_X,optionSeven)) petya = true;
    if (regex_match (result_O,optionSeven)) vanya = true;

    auto optionEight= regex (".*048.*");
    if (regex_match (result_X,optionEight)) petya = true;
    if (regex_match (result_O,optionEight)) vanya = true;


    if (vanya && result_X.length() == result_O.length() - 1)   return "Vanya won";
    else if (petya && result_O.length() == result_X.length())   return "Petya won";
    else if ( vanya && petya || (vanya && result_X.length() > result_O.length()) ||
            result_O.length() > result_X.length()) return "Incorret";
    else return "Nobody";

}

int main() {

        char line[9];
        string game;

        for (int i = 0; i < sizeof(line); ++i) {
            cin >> line[i];
            game += line[i];
        }

        cout << gameOver(game);

    return 0;
}