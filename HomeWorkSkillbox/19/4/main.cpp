#include <iostream>

using namespace std;

enum notes{
    C,    //! C - нота до
    D,        //!      D - ре
    E,        //!      E - ми
    F,        //!     F - фа
    G,        //!     G - соль
    A,  //!     A - ля
    H   //!     H или B - си
};
bool checkKey(const string& buf){
    for (int i = 0 ; i < buf.length() ; ++i)
        if (buf[i]  < 1 || buf[i] > 7 ) return false;
    return true;
}

void enterMusic(string& track){
    string buf;

    for (int i = 0; i < 12; ++i){
        cin >> buf;
        if (!checkKey(buf)){
            --i;
            buf = "";
            cout << "The last combination you entered is not correct. Try again";
        }
        track += buf + ' ';
    }

}

void viewMusic (const string& music){
    int one, two, free, four, five, six, seven;

    one = 1 << C ;
    two = 1 << D ;
    free = 1 << E;
    four = 1 << F;
    five = 1 << G;
    six = 1 << A;
    seven = 1 << H;

    cout << one << " " << two << " " << free << " " << four << " " <<
    five << " " << six << " " << seven;

}


int main() {
    string track;
    //enterMusic(track);
    viewMusic(track);

    return 0;
}
