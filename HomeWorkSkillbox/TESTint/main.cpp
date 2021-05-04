#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>
#include <fstream>


struct a {
    std::vector<int> x;
};

int main() {
    using namespace std;

    a hi;
    for (int i = 0;i < 6 ; ++i) {
        int t;
        cin >> t;
        hi.x.push_back(t);
    }

    for (int i = 0; i< hi.x.size(); ++i){
        cout << hi.x[i] << endl;
    }

    return 0;
}
