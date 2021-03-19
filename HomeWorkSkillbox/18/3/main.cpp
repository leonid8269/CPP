#include <iostream>
#include <vector>

using namespace std;

void sorting(vector<int>& vec){
    for (int i = 0 ; i < vec.size() ; ++i){
        for (int j = 0; j < vec.size() - i - 1; ++j){

            if(vec[j] > vec[j+1]){
                int buf = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = buf;
            }
        }
    }


}


int main() {
    vector<int> vec;

    int num = 0;
    cout << "Enter numbers: ";
    while (true && num != -2 ){

        cin >> num;
        vec.push_back(num);

        if (num == -1 && vec.size() > 5 ){
            vec.pop_back();
            sorting(vec);
            cout << vec[4] << " = Fifth numbers in the sorted vector. View of the sorted vector:\n";
            for (int i = 0 ;i < vec.size(); ++i) cout << vec[i]<< " ";
            cout << "\nEnter more numbers: ";
        }else if (num  ==  -1 && vec.size() <= 5) {
            cout << "Minimum number of figures five\n";
            vec.pop_back();
            cout << "Enter more numbers (Enough back " <<  5 - vec.size()   <<" ) : ";
        }

    }
    vec.pop_back();
    sorting(vec);
    for (int i = 0; i < vec.size(); ++i)  cout << vec[i]<< " ";

    return 0;
}
