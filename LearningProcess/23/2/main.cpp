#include <iostream>
#include <fstream>


int main() {
    using namespace std;

    ofstream file("..\\file.txt");
    file.setf(ios::showpos); // показывает явно.  x > 0 то +x, x < 0 то -x, для чисел
    file.setf(ios::boolalpha); // чтобы буль был false\true а не 0\1
    file.setf(ios::showpoint); // чтобы записать вещественное число с точкой если оно без дробной части)
    file.precision(3);
    double temp = -21;
    file << temp << " ";
    bool light = true;
    file << light << endl;

    double temps[] = {15.5, 20, 0, 8.3, -2};
    char* conditions[] = {"sunny", "cloudy", "windy", "snowy", "stormy"};

    for (int i= 0; i < 5;++i){
        file.width(); // ширина , отст
        file << temps[i];
        file.width(10);
        file << conditions[i] << endl;
    }

    file.close();
    return 0;
}
