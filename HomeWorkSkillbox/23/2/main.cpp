#include <iostream>
#include <fstream>
#include <ctime>


int main() {
    using namespace std;
    srand(time(nullptr));

    ofstream pictures ("..\\pic.txt");

    int width = 0;
    cout << "Enter the width:\n";
    cin >> width;

    cout << "Enter the height:\n";
    int height = 0;
    cin >> height;

    for (int i = 0;i < width ;++i){
        for (int j = 0; j < height ;++j)pictures << rand() % 2;
        pictures << endl;
    }

    pictures.close();
    return 0;
}
