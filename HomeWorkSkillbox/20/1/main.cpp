#include <iostream>

using namespace std;


void swap(int* ap, int* bp){
    *ap += *bp;
    *bp = *ap - *bp;
    *ap -=  *bp;
}

int main() {

    int a = 10, b = 20;

    int *ptrA = &a; // указатель на а
    int *ptrB = &a; // указатель на б

    swap(ptrA, ptrB);
    cout << a << " " << b;

    return 0;
}
