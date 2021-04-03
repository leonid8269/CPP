#include <iostream>

using namespace std;


void swap(int& a, int& b){
    a += b;
    b = a - b;
    a -=  b;
}

int main() {

    int a = 10, b = 20;
    swap(a,b);

    cout << a << " " << b;

    return 0;
}
