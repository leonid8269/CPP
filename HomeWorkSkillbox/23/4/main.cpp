#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include <math.h>

void newBank (std::vector<int>& banknotes){  //the function is called when the bank is new without notes
    using namespace std;
    srand(time(nullptr));
    ofstream bank("..\\bank.bin", ios::binary);

    for (int i = 0;i < banknotes.size(); ++i ){
        int buf = rand() % 8 + 1;
        if ( buf == 1 ) {
            banknotes[i] = 100;
            bank << banknotes[i] << endl;
        }
        else if (buf == 2) {
            banknotes[i] = 200;
            bank << banknotes[i] << endl;
        }
        else if (buf == 3) {
            banknotes[i] = 500;
            bank << banknotes[i] << endl;
        }
        else if (buf == 4) {
            banknotes[i] = 1000;
            bank << banknotes[i] << endl;
        }
        else if (buf == 5) {
            banknotes[i] = 2000;
            bank << banknotes[i] << endl;
        }
        else {
            banknotes[i] = 5000;
            bank << banknotes[i] << endl;
        }
    }
    bank.close();
}

bool checkFullness(){ // checking for emptiness
    using namespace std;
    ifstream bank("..\\bank.bin", ios::binary);
    if(!bank.is_open()) {
        cout << "Error opening file!\n";
        return false;
    }else {
        int buf = 0;
        int line = 0;
        while (!bank.eof()){
            bank >> buf;
            ++line;
        }
        if (line >= 1000) return true;
    }
    bank.close();

    return false;
}
void restartingProgram(std::vector<int>& banknotes) {
    using namespace std;
    ifstream bank("..\\bank.bin",ios::binary);
    for (int i = 0 ;i < banknotes.size() ;++i) bank >> banknotes[i];
    bank.close();

}

void withdrawalAndAdded(std::vector<int>& arr ,int bankHun, int bankTwoHun, int bankFiveHun,
                        int bankThous, int bankTwoThous, int bankFiveThous, int money, char operation){
    using namespace std;


    if (operation == '-'){  //withdrawal cash

        int hundred = 0 , twoHundred  = 0, fiveHundred = 0,
        thousand = 0 , twoThousand = 0,fiveThousand = 0;

        fiveThousand =  money / 5000;
        money -= fiveThousand * 5000;

        twoThousand = money / 2000;
        money -= twoThousand * 2000;

        thousand = money / 1000;
        money -= thousand * 1000;

        fiveHundred = money / 500;
        money -= fiveHundred * 500;

        twoHundred = money / 200;
        money -= twoHundred * 200;

        hundred = money / 100;


        if ( fiveThousand > bankFiveThous) {
            int delta = fiveThousand - bankFiveThous;
            fiveThousand -= delta;
            int buf = delta * 5000;
            twoThousand += buf / 2000;
            buf -= 5000 * delta;
            thousand += buf / 1000;
        }
        if (twoThousand > bankTwoThous) {
            int delta = twoThousand - bankTwoThous;
            thousand += delta * 2;
        }
        if (thousand > bankThous) {
            int delta = thousand - bankThous;
            fiveHundred += delta * 2;
        }
        if(fiveHundred > bankFiveHun){
            int delta = fiveHundred - bankFiveHun;
            fiveHundred - delta;
            int buf = delta * 500;
            twoHundred += buf / 200;
            buf -= 500 * delta;
            hundred += buf / 100;
        }
        if (twoHundred > bankTwoHun){
            int delta = twoHundred - bankTwoHun;
            twoHundred - delta;
            hundred += delta * 2;
        }
        if (hundred > bankHun){
            cout << "I can't give you that amount\n";
            exit(2);                                            //EXIT from program
        }

        for (int i = 0; i < arr.size(); ++i){
            if (fiveThousand > 0 && arr[i] == 5000) {
                 arr[i] = 0;
                 fiveHundred --;
            }
            if (twoThousand > 0 && arr[i] == 2000){
                arr[i] = 0;
                twoThousand --;
            }
            if (thousand > 0 && arr[i] == 1000){
                arr[i] = 0;
                thousand--;
            }
            if (fiveHundred > 0 && arr[i] == 500){
                arr[i] = 0;
                fiveHundred --;
            }
            if (twoHundred > 0 && arr[i] == 200){
                arr[i] = 0;
                twoHundred --;
            }
            if (hundred > 0 && arr[i] == 100){
                arr[i] = 0;
                hundred --;
            }
        }

        ofstream bank("..\\bank.bin",ios::binary);
        for (int i = 0 ;i < arr.size() ;++i) {
            bank << arr[i];
            bank << endl;
        } bank.close();


    }else if (operation == '+'){ //added money

        cout << "df\n";

    }

}

void atmOperation ( std::vector<int>& banknotes, int& sumCash){ //
    using namespace std;

    int bankHun = 0;
    int bankTwoHun = 0;
    int bankFiveHun = 0;
    int bankThous = 0;
    int bankTwoThous = 0;
    int bankFiveThous = 0;


    for (int i = 0; i < banknotes.size(); ++i){
        sumCash += banknotes[i];
        if (banknotes[i] == 100) bankHun++;
        else if (banknotes[i] == 200) ++bankTwoHun;
        else if (banknotes[i] == 500) ++bankFiveHun;
        else if (banknotes[i] == 1000) ++bankThous;
        else if (banknotes[i] == 2000) ++bankTwoThous;
        else if (banknotes[i] == 5000) ++bankFiveThous;
    }

    cout << "Available to you (for withdrawal!) : \n"
                 "100 = " <<  bankHun << " banknotes!\n"
                 "200 = " <<  bankTwoHun << " banknotes!\n"
                 "500 = " <<  bankFiveHun << " banknotes!\n"
                 "1000 = " << bankThous << " banknotes!\n"
                 "2000 = " << bankTwoThous << " banknotes!\n"
                 "5000 = " << bankFiveThous << " banknotes!\n"
                 "Maximum withdrawal limit! " << sumCash << std::endl;

    cout << "Good day!\n"
            "How match do you want to withdraw?\n";

    int money;
    char operation;
    string buf = "";
    while (true) {
        cin >> buf;
        if (!(buf[0] == '+' || buf[0] == '-')){
            cout << "I don't understand what you want to do\n";
            continue;
        }

        operation = buf[0];
        money = abs(stoi(buf));

        if (money > sumCash) {
            cout << "Dear, ATM does not have enough funds! Try again\n\a";
            continue;
        }
        break;
    }

    if (money % 100 > 0) {
        money -= money % 100;
        cout << "I can only give you one\n" << money;
    }



    withdrawalAndAdded(banknotes, bankHun,  bankTwoHun,  bankFiveHun,
             bankThous,  bankTwoThous,  bankFiveThous,
             money, operation);

}

int main() {
    using namespace std;
    vector<int> banknotes (1000, 0); // to avoid errors the value is zero

    if (!checkFullness()) newBank(banknotes); // on first launch
    else restartingProgram(banknotes);// when restarting after closing the app
    int sumCash = 0; //amount in the bank
    atmOperation(banknotes, sumCash);


    return 0;
}
