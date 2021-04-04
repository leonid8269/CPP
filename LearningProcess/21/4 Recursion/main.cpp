#include <iostream>

int fib(int n){
    if(n == 0 || n ==1 ) return 1;
    return fib(n - 1) + fib(n - 2);
}


int swap(int& a, int& b){
    a += b;
    b = a - b;
    a = a - b;
}

int gcd (int a, int b){ // алгоритм евклида
    if(b>a) swap(a,b);
    if(a % b == 0) return b;

    return gcd(b, a % b);

}
int main() {
    for (int i = 0; i < 6 ; ++i){
        std::cout << fib(i) << " ";
    }

    int a = 10;
    int b = 20;

    std::cout << gcd(30,20);


    return 0;
}
