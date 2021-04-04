#include <iostream>

using namespace std;

int main() {
   int i = 10;
   int& j = i;

   cout << j << endl;
   i = 12;
   cout << j << endl;
   j = 15;
   cout << i << endl;



    return 0;
}
