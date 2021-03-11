#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main() {
    int add = 0;
    vector<int> list{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; // для удобства чтобы не писать первые 15 чисел
    while (add != -1) {
        cin >> add;
        list.push_back(add);
        if (list.size() > 20){
            list.erase(list.begin());
        }

    }

    for ( int i = 0; i < list.size() ; ++i){
        cout << list[i] << " ";
    }
    return 0;
}
