#include <iostream>
#include <vector>
#include <sstream>
#include <string>

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

void wiew(string& track){

    for (int i = 0;i < track.length()  ; ++i) {
        if (track[i] & DO) cout << "Do ";
        else if (track[i] & RE) cout << "RE ";
        else if (track[i] & MI) cout << "MI ";
        else if (track[i] & FA) cout << "FA ";
        else if (track[i] & SOL) cout << "SOL ";
        else if (track[i] & LA) cout << "LA ";
        else if (track[i] & SI) cout << "SI ";
        else cout << endl;
    }

}

int main() {
    string track;
    cout << "Enter your combination: ";
    for (int i = 0; i < 12 ; ++i) {
       string buf = "";
       cin >> buf;
        if (buf > "0" && buf < "8") {
            track += buf;
        } else {
            --i;
        }
    }


    return 0;
}
