#include <iostream>
#include <vector>

using namespace std;

int swap(int& a, int& b){
    a += b;
    b = a - b;
    a -= b;
}

void swapvec(vector<int>& vec, int* arr){
    for (int i = 0; i < 5 ; ++i)swap(vec[i], *(arr + i));
}

int main() {

    vector<int> vec = {1,2,3,4,5};
    int arr[] = {6,7,8,9,10};

    swapvec(vec, arr);

    for (int i = 0; i < 5 ; ++i)cout << vec[i];
    cout << endl;
    for (int i = 0; i < 5; ++i) cout << arr[i];


    return 0;
}
