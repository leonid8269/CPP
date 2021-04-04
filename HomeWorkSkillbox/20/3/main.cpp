#include <iostream>

using namespace std;


bool substr(char* a, char* b){
     int sizeA = 0, sizeB = 0;

     for (int i = 0; *(a + i) != '\0' ; ++i) ++ sizeA;
     for (int i = 0; *(b + i) != '\0' ; ++i) ++ sizeB;

     int count = 0;
     for (int i = 0;i < sizeA - sizeB ; ++i){
         if (*(a + i) == *(b + i)){
             for (int j = 0; j < sizeB; ++j){
                 if (*(a + i) == *(b + i)){
                     ++ count;
                 }else{
                     count = 0;
                 }
             }
         }
     }
    if (count == sizeB) return true;
    else return false;

   }


int main() {

    char* first = "babushka";
    char* second = "bush";
    char* third = "pushka";

    cout << substr(first, third) << " " << substr(first, second);

    return 0;
}
