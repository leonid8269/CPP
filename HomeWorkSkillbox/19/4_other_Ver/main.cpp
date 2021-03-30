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


void view(stringstream& track){

    vector<int> arr{};

    for(int i = 0; i < 12 ; ++i) track >>arr[i];

    for (int i = 0;i < arr.size(); ++i) {
        if (arr[i] & DO) cout << "Do ";
        else if (arr[i] & RE) cout << "RE ";
        else if (arr[i] & MI) cout << "MI ";
        else if (arr[i] & FA) cout << "FA ";
        else if (arr[i] & SOL) cout << "SOL ";
        else if (arr[i] & LA) cout << "LA ";
        else if (arr[i] & SI) cout << "SI ";
        else cout << endl;
    }

}

int main() {
    stringstream track;
    cout << "Enter your combination: ";
    for (int i = 0; i < 12 ; ++i) {
       string buf = "";
       cin >> buf;
        if (buf > "0" && buf < "8") {
            track << buf;
            track << " ";
        } else {
            --i;
        }
    }


    return 0;
}
