#include <iostream>
#include <cmath>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::sqrt;
using std::pow;

struct math_vector{
    double x;
    double y;
};

void initialization_math_vec(math_vector& first, math_vector& second){
    cout << "Enter the coordinate of the first vector\n";
    cin >> first.x >> first.y;

    cout << "Enter the coordinate of the second vector\n";
    cin >> second.x >> second.y;
}

void add (math_vector& first, math_vector& second){

   initialization_math_vec (first, second);

   first.x += second.x;
   first.y += second.y;
   cout << "RESULT: " << first.x << " " << first.y << endl;
}

void subtract(math_vector& first, math_vector& second){
    initialization_math_vec(first, second);

    first.x -= second.x;
    first.y -= second.y;
    cout << "RESULT: " << first.x << " " << first.y << endl;
}

void scale(math_vector& first){
    cout << "Enter the coordinate of the vector:\n";
    cin >> first.x >> first.y;

    cout << "Enter the scalar:\n";
    int scalar {};
    cin >> scalar;

    first.x *= scalar;
    first.y *= scalar;

    cout << "RESULT: " << first.x << " " << first.y << endl;
}

void length(math_vector& first) {
    cout << "Enter the coordinate of the vector\n";
    cin >> first.x >> first.y;
    cout << "The length of vector is " << sqrt(pow(first.x, 2) + pow(first.y, 2)) << endl;
}

void normalize(math_vector& first){
    cout << "Enter the coordinate of the vector\n";
    cin >> first.x >> first.y;

   double buf =  1. / sqrt(pow(first.x, 2) + pow(first.y, 2));

   cout << "The vector after normalize " << first.x * buf << " " << first.y * buf << endl;


}


int main() {

    string buf{};
    cout << "Enter 'add' or 1 to adding two vectors;\n"
         << "Enter 'subtract' or 2 to subtracting two vectors;\n"
         << "Enter 'scale' or 3 to multiplying a vector by a scalar;\n"
         << "Enter 'length' or 4 to finding the length of a vector;\n"
         << "Enter 'normalize' or 5 to normalize a vector;\n\n";

    cin >> buf;
    int command {};
    if (buf == "add"  || buf == "1") command = 1;
    else if (buf == "subtract"  ||buf == "2") command = 2;
    else if (buf == "scale"     || buf == "3") command = 3;
    else if (buf == "length"    || buf == "4") command = 4;
    else if (buf == "normalize" || buf == "5") command = 5;
    else command = 666;

    math_vector first{};
    math_vector second{};
    switch (command) {
        case (1):
            add(first, second);
            break;
        case (2):
            subtract(first, second);
            break;
        case (3):
            scale(first);
            break;
        case (4):
            length(first);
            break;
        case (5):
            normalize(first);
            break;
        default:
            cout << "Command not found!\a\n";
            break;
    }

    return 0;
}
