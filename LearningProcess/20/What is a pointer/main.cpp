#include <iostream>

using namespace std;

int main() {

    int i = 10;

    int* pi = &i; // указатель на адрес

    cout << pi << endl; // покажет адрес в памяти
    cout << *pi << endl;    // разименованная
    *pi = 20;   // разименуем инициализируем другое значение и вывидем на экран переменную i



    cout << pi << endl;

    cout << i << endl; // вот она эта i

 

    return 0;
}
