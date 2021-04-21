#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>
#include <fstream>

void w (int a, int b = 3){
    std::cout << a+b;
}

int main() {
    using namespace std;

    int a, b;
    cin >> a;
    w(a);

    return 0;
}
