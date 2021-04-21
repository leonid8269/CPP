#include <iostream>
#include <fstream>


int main() {
    using namespace std;

    ifstream riv ("..\\river.txt");

    if(!riv.is_open()) {
        cout << "Error opening file\a\n";
        return 1;
    }else {
        ofstream bas ("..\\basket.txt",ios::app);
        string buf;

        string fisherman;
        cout << "What kind of fish will you catch?\n";
        cin >> fisherman;

        while(!riv.eof()){
            riv >> buf;
            if(buf == fisherman){
                bas << fisherman << endl;
            }
        }
        bas.close();
    }
    riv.close();


    int sum = 0;
    ifstream basket("..\\basket.txt");
    while (!basket.eof()){
        string buf;
        basket >> buf;
        sum ++;
    }

    basket.close();

    cout << sum - 1 << "Total fish caught \n"; // - 1 because a line feed is involved

    return 0;
}
