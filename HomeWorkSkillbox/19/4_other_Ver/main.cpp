#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

enum notes {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

void wiew(int& track){

    if (track & DO ) cout << "Do ";
    if (track & RE ) cout << "RE ";
    if (track & MI ) cout << "MI ";
    if (track & FA ) cout << "FA ";
    if (track & SOL ) cout << "SOL ";
    if (track & LA ) cout << "LA ";
    if (track & SI ) cout << "SI ";
    cout << endl;

}



int main() {
    stringstream track;

    for (int i = 0; i < 12; ++i){
        string buf;
        cin >> buf;
        track << buf + " ";
        buf = "";
    }



    return 0;
}
