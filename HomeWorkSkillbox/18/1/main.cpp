#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4}; // нахожджение максимального значения из нескольких
    int buf = 0, max = 0;
    int indexOne = 0, indexTwo = 0;

    for(int i = 0; i < arr.size() ; ++i){

        for (int j = i; j < arr.size() ;++j){
            buf += arr[j];
            if (buf > max) {
                max = buf;
                indexTwo = j;
                indexOne = i;
            }
        }
        buf = 0;
    }

    cout << "Index One = " << indexOne << ". Index two = " << indexTwo << ". Maximum = " << max;

    return 0;
}
