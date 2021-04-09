#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>



int main() {
    using namespace std;
    bool a = false;
    bool b = true;
    bool c  = (!(a) && !(b));

    cout << " a = false, b = true. result " << c << endl;

    a = true;
    b = false;

    c = (!(a) && !(b));
    cout << "a = true, b = false. result " << c << endl;


    a = false;
    b = false;
    c = (!(a) && !(b));
    cout << "a = false, b = false result " << c << endl;


    a = true;
    b = false;
    c = (!(a) && !(b));
    cout << "a = true, b = true . result " << c;

    return 0;
}
