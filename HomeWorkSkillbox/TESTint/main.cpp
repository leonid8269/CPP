#include <iostream>
#include <cstdlib>
#include <vector>]
#include <cmath>
#include <sstream>


using namespace std;

enum music {
    DO,RE,MI,FA,SOL,LA,SI
};


void finding (int& mas){
    mas + 1;

    if (mas == 1 << DO) cout << "Do ";
    else if (mas == 1 << RE) cout << "Re ";
    else if (mas == 1 << MI) cout << "Mi ";
    else if (mas == 1 << FA) cout << "Fa ";
    else if (mas == 1 << SOL) cout << "Sol ";
    else if (mas == 1 << LA) cout << "La ";
    else if (mas == 1 << SI) cout << "Si ";
    else cout << "Error";


}

int main() {
    vector<int> arr(12);

    for (int i = 0; i < arr.size(); ++i ) cin >> arr[i];

    for (int i = 0;i < arr.size() ; ++i) {
        finding(arr[i]);

    }
    return 0;
}
