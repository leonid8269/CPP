#include <iostream>

using namespace std;

int variants(int step){
    if(step < 1) return 0 ;

}

int main() {
    int step = 0;
    int method = 0;
    cout << "What step will we jump to?\n";
    cin >> step;

    cout << variants(step);

    return 0;
}
