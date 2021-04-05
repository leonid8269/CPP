#include <iostream>

using namespace std;

void mirror(int* ptrArr, int size){

    int half = 0;
    size % 2 == 0 ? half = size /2 - 1 : half = size / 2;

    for (int i = 0; i <= half  ; ++i){
        int buf = 0;
        buf = *(ptrArr + (size - 1) - i);
        *(ptrArr + (size - 1) - i) = *(ptrArr + i);
        *(ptrArr + i) = buf;
    }
}

int main() {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);

    int *ptrArr = arr;

   mirror(ptrArr, size);

   for (int i = 0; i < size ; ++i)cout << arr[i];


    return 0;
}
