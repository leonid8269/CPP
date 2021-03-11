#include <iostream>
#include <vector>


using std::cout;
using std::vector;

int main() {
    vector<float> price{25.2, 123.6, 1.9, 55.7, 1, 23, 2};
    vector<int> purchases{5,5,2,2,1};
    float sum = 0.;
    for(int i = 0 ;i < purchases.size() ; ++i ){
        sum += price[purchases[i]];
    }

    cout << sum;
    return 0;
}
