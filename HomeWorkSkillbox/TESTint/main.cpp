#include <iostream>
#include <cstdlib>
#include <vector>]
#include <cmath>
#include <sstream>


using namespace std;




int main() {

    string buf;

    getline(cin,buf);

    stringstream text;

    text << buf;

    cout << text.str() << endl;


    buf.clear();
    cout << "buf " << buf;

    return 0;
}
