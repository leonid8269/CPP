#include <iostream>
#include <fstream>
#include <cstring>

/*!
 * запись массивов данных
 */


int main() {
    using namespace std;
    int control_sum = 0;
    int arr[1000];
    for (int i = 0; i <1000 ; ++i ) {
     arr[i] =  rand() % 51; // от нуля до 50
     // rand() % 51 + 100 - это от 100 до 150!
     control_sum += arr[i];
    }
    cout << "control sum = " << control_sum << endl;
    ofstream file("..\\file.bin", ios::binary);
    for (int i = 0; i < 1000; ++i) file << arr[i] << endl;
    file.close();

    ifstream numbers ("..\\file.bin", ios::binary);
    int sum = 0;
    while (!numbers.eof()){
        int buf = 0;
        numbers >> buf;
        sum += buf;
    }
    cout << sum << " sum \n";
    numbers.close();



    return 0;
}
