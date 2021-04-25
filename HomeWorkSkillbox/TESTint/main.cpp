#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>
#include <fstream>



int main() {
    using namespace std;
    string name = "leonid";
    int len = 2;
    cout << name.size() << endl;
    name.resize(len);
    cout << name.size();

    return 0;
}
