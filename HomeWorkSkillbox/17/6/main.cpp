#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;


int main() {


    vector<float> V(4); //
    vector<float> R(4); //
    float M[4][4];          //

    cout << "Enter numbers in vector V:\n";
    for (int i = 0 ; i < 4 ; ++i){
        cin >> V[i];
    }

    cout << "Enter number in array M:\n";
    for (int i = 0 ;i < 4 ; ++i){
        for (int j = 0 ;j < 4 ;++j){
            cin >> M[i][j];
        }
    }

    for (int i = 0; i < 4 ; ++ i){
        for (int  j = 0 ;j < 4 ; ++ j){
            R[i] += M[i][j] * V[j];
        }
    }

    for (int i = 0; i < 4; ++i){
        cout << R[i] << "\t";
    }



    return 0;
}
