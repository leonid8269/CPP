#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> array = { 11, 2, 15, 7};
    int res = 9, buf = 0, buf1 = 0 ;


    for (int i = 0; i < array.size() ; ++i ){
        for (int j = 0; j < array.size() ; ++j){
            if (array[i] + array[j] == res ) {
                 buf = array[i];
                 buf1 = array[j];
            }
        }
       //if (stop) break; // без нее выводит два раза один и тот же ответ с преставленными меж собой местами xD
    }
    cout << buf << " " << buf1;

    return 0;
}
