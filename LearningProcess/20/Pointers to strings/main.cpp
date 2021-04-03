#include <iostream>


using namespace std;

int main() {

    char s[5] = {'h', 'e', 'l', 'l', 'o'};

    const char* a = "Hello world!";
    const char b [] = "Hello world!";

    int q[] = {1,2,3};
    cout << q << endl; // выведет адрес
    cout << b << endl; // выведет всю строку,
    cout << &b << endl; // с амперсантом выдает адрес

    char x[] = "Hello World";
    for(int i = 0; *(x+i) != '\0' ;++i)cout << *(x+i);

    return 0;
}
