#include <iostream>

using namespace std;

void mirror(int& arr, int size){
    for (int i = size - 1; i >= 0; --i){
        cout <<  (arr + i)  << " ";
    }
}

int main() {
   int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);

   mirror(*arr, size);


    return 0;
}
