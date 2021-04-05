#include <iostream>

using namespace std;


void swap(int* ap, int* bp){
    *ap += *bp;
    *bp = *ap - *bp;
    *ap -=  *bp;
}

int main() {

    int a = 10, b = 20;

    swap(&a,&b);
    cout << a << " " << b;

    return 0;
}
