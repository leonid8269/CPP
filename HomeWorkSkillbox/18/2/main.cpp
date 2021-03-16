#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> array = {2, 11, 15, 7};
    int res = 9;
    bool stop = false; // чтобы не создавать буфферные переменные)

    for (int i = 0; i < array.size() ; ++i ){
        for (int j = 0; j < array.size() ; ++j){
            if (array[i] + array[j] == res ) {
                cout << "First number = " << array[i] << ". Second number = " << array[j] << endl;
                stop = true;
            }
            break;
        }
        if (stop) break; // без нее выводит два раза один и тот же ответ с преставленными меж собой местами xD
    }

    return 0;
}
