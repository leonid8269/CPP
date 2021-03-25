#include <iostream>

using namespace std;


bool checkKey(const string& buf){
    for (int i = 0 ; i < buf.length() ; ++i)
        if (buf[i]  < '1' || buf[i] > '7' ) return false;
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
        else track += buf + ' ';
    }
}

void viewMusic (const string& music){

    for (int i = 0; i < music.length() ; ++i){
        if (music[i] == '1') cout << "do ";
        else if (music[i] == '2') cout << "re ";
        else if (music[i] == '3') cout << "mi ";
        else if (music[i] == '4') cout << "fa ";
        else if (music[i] == '5') cout << "sol ";
        else if (music[i] == '6') cout << "la ";
        else if (music[i] == '7') cout << "si ";
        else cout << endl;
    }

}


int main() {
    string track;
    enterMusic(track);
    viewMusic(track);

    return 0;
}
