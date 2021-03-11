#include <iostream>

using std::cout;
using std::cin;
using std::endl;



int main() {
    int building[5];
    int total_R = -1, total_L = 0;           // R - registered residents, L - level residents

    do {
        cout << "Total registered residents: ";
        cin >> total_R;
    }while (total_R < 0);

    for(int i = 0 ; i != 5 ;  ++ i ) {
        cout << "How many people are on the floor: \n";
        cin >> building[i];
        total_L += building[i];
    }

    float result = ((float)total_L * 100) / (float) total_R;
    cout << "Percentage of people in self-isolation " << (int) result << " %." << endl;

    return 0;
}
