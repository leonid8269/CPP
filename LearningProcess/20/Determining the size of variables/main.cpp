#include <iostream>

using namespace std;

int main() {

    int a = 3;

    cout << sizeof(a)<< " " << sizeof(int)<< endl; // a = 4 потому что он тип инт.

    int b = 20;
    double c = 12;

    int* pb = &b;
    double* pc = &c;

    cout << sizeof(b) << " " << sizeof(pb) << endl; // размеры одинаковые 4 байта и 4 байта
    cout << sizeof(c) << " " << sizeof(pc) << endl;         // размеры разные 8 абйт и 4 байта
                                                    //так как указатели на любую переменную имеют размер 4 байта

     int ar[5] = {76,56,3,4,5};

     cout << ar << endl;   // покажет адрес в памяти
     cout << *ar << endl; //если разименовать вернется первый элемент в массиве

     int* par = ar + 1;
     cout << *par << endl; // таким образом обращаемся к 2 эл. массива

     //!научимся работать с циклами.

     int mas[5] = {5,4,8,6,4};
     for(int i = 0;i < 5 ; ++i){
         *(mas + i) *= 2;
     }

     for(int i = 0;i < 5 ;++ i){
         cout << *(mas + i) << " " ;
     }


     //! будем обращаться в память дальше чем есть массив) как то так

     int massive[5] = {1,232,13,4,2};

     int* pmassive = massive + 10;

     cout << endl  << pmassive << " " << *pmassive;

    return 0;
}
