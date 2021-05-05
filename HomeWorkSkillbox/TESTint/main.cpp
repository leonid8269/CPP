#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>
#include <fstream>


struct a {
    std::vector<int> x;
};

int main() {
    using namespace std;
    double a;
    int x = 9, y = 2;

    a = (double)x / y;
    cout << a;
    return 0;
}
