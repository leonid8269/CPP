#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

enum notes {
    DO = 1,
    RE,
    MI,
    FA,
    SOL,
    LA,
    SI
};

void initialization (const string& track, string& music ){


    for (int i = 0; i < track.length(); ++i ) {
        if ((track[i] - '0')  == DO) music +=  "Do ";
        else if ((track[i] - '0') == RE) music += "Re ";
        else if ((track[i] - '0') == MI) music += "Mi ";
        else if ((track[i] - '0') == FA) music += "Fa ";
        else if ((track[i] - '0') == SOL) music += "Sol ";
        else if ((track[i] - '0') == LA) music += "La ";
        else if ((track[i] - '0') == SI) music += "Si ";

    }

}


int main() {
    string music;
    for (int i = 0; i < 12 ; ++i) {
       string buf = "";
       cin >> buf;
       for (int j = 0;j < buf.length() ; ++j ) {
           if (buf[j] > '0' && buf[j] < '8') {
               initialization(buf, music);
           } else {
               --i;
               cout << "Sorry friend, you enter not correct a note, please try again\n";
               break;
           }
       }
    }


    cout << music;

    return 0;
}
