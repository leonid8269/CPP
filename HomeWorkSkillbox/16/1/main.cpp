#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;


int main(){
   vector<int> number;

   int iteration;
   cout << "How many numbers will be entered? \n";
   cin >> iteration;
   int count;
   for (int i = 0;i != iteration ; ++ i){
       cin >> count;
       number.push_back(count);
   }

   int del;
   cout << "What numbers to remove? \n";
   cin >> del;

   vector<int> buffer;

   for (int i = 0;i < number.size() ; ++i){
       if (number[i] != del) buffer.push_back(number[i]);
   }
    number.clear();         // не зачем ему занимать память)

    for (int i = 0 ;i < buffer.size() ; ++i){
        cout << buffer[i] << " ";
    }


    return 0;
}
