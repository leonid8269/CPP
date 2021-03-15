#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> array = {2, 11, 15, 7};
    int res = 9;

    for (int i = 0; i < array.size() ; ++i ){
        for (int j = 0; j < array.size() ; ++j){
            if (array[i] + array[j] == res ) {
                cout << "First number = " << array[i] << ". Second number = " << array[j] << endl;
            }
            break;
        }
    }


    return 0;
}
