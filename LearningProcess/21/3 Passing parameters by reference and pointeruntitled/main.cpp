#include <iostream>
#include <vector>

using namespace std;


void foo (int* i){ // принимает адрес ссылки
    *i += 10;
    *i *= 2;
}

void fuck(int& i){ // принимает ссылку(пресдоним)
    i += 10;
    i *= 2;
}

void shlyapa(vector<int>& vec){
    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i] << " ";
        vec[i] *= 2;
    }
}

int main() {
    int a = 10;
    foo(&a);
    cout << a << " ";

    int b = 12;
    int* pb = &b;
    foo(pb);

    cout << b << endl;

    fuck(b);
    cout << b << endl;

 // работа с вектором

    vector<int> arr = {1,2,3,4,5,6,7};
    shlyapa(arr);

    return 0;
}
