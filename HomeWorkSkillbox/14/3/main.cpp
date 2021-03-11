#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::string;
using std::endl;


string checkEmail(string email){

    int firstHalf = 0;
    bool dog = true;        //считаем что @ уже есть!
    bool doubleDot = false; // считаем что двойной точки еще нет
    for (int i = 0 ;i < email.length() ; ++i){
        if ((email[i] >= 'A' && email[i] <= 'Z') || (email[i] >= 'a' && email[i] <= 'z')|| (email[i] >= '0'
                && email[i] <= '9') || email[i] == '!' || email[i] == '#' || email[i] == '$'|| email[i] == '%'
                || email[i] == '&' || email[i] == '\''  || email[i] == '*' || email[i] == '+'|| email[i] == '-'
                || email[i] == '/' || email[i] == '=' || email[i] == '?' || email[i] == '^'|| email[i] == '_'
                || email[i] == '`' || email[i] == '|' || email[i] == '}' || email[i] == '~'|| email[i] == '@'
                || email[i] == '.') { 

            if (email[0] == '.' || email[email.length() - 1] == '.') return "NO!1\n";

            else if ( doubleDot && email[i] == '.') return "No!\n"; // эта конструкция надеюсь лучше)
            else if (email[i] == '.') doubleDot = true;
            else if (email[i] != '.') doubleDot = false;


             if (email[i] == '@' ) {// проверка первой половины до этого места
                firstHalf = i;
                dog = false ;
                if (email.length() - firstHalf > 64 || email.length() == firstHalf + 1
                        || (i < 1 || i > 64)) return "NO!7\n"; // проверка на длину.

                else if (email[i-1] == '.' ) return "NO!2\n";
                for (i = firstHalf + 1; i < email.length() ; ++ i){        // чек второй половины
                    if ( (email[i] >= 'A' && email[i] <='Z') || (email[i] >= 'a' && email[i] <= 'z')
                             || email[i] == '.' || email[i] == '-' || (email[i] >= '0' && email[i] <='9')){

                        if ( doubleDot && email[i] == '.') return "No!\n";
                        else if (email[i] == '.') doubleDot = true;
                        else if (email[i] != '.') doubleDot = false;

                    }else return "NO!4\n";
                }
            }
        }else return "NO!5\n";
    }
    if (dog) return "NO!6\n";
   return "Yes!\n";
}

string checkIP(string ip){
    int dot = 0;
    string sum;
    bool point = true;
    int result = 0;

    if (ip.length() < 7 || ip.length() > 15 || (ip[0] == '.' || ip[ip.length() - 1] == '.')) return "NO!=)\n";

    for (int i = 0; i < ip.length(); ++i) {
        if (ip[i] == '.' || (ip[i] >= '0' && ip[i] <= '9')) { // только цифры и точка.

            if (ip[i] != '.') {                                             // цифры от 0 - 9.


                sum += ip[i];
                if (sum[0] == '0' && (sum [1] >= '0' && sum[1] <= '9' )) return "NO!\n";
                point = false;
                if (sum.length() == 3) {
                    result = ((sum[0] - '0') * 100) + ((sum[1] - '0') * 10) + (sum[2] - '0');
                    if (result > 255) return "NO!\n";

                } else if (sum.length() > 3) return "NO!\n";


            } else {            // точки
                if (point) return "NO!\n"; //если точки вместе стоят

                dot++;
                point = true;   // счетчик и   флаг на точку
                sum = "";       // обнуление буфера

            }


        } else return "No!5\n";

        }



    if (dot != 3) return "NO!6\n";

    return "Yes!\n";
}


string comparator(string a, string b){

        int facts = 0, points = 0, minus = 0, numeral = 0;

        for (int i = 0 ; i < a.length() ; ++i ){                    // проверка первого числа на "вещественность"
            if ( ! (a[i] == '.' || (a[i] >= '0' && a[i] <= '9') || a[i] == '-') ||
                    (a[i] >= 'A' &&  a [i] <='Z' && a[i] >='a' && a[i] <='z')) {
                    -- facts;

            }else {
                if (a[i] == '.') ++ points;
                if ( a[i] == '-' ) {
                    ++ minus;
                    if (a[0] != '-' ) --facts;
                }
                if (a[i] >= '0' && a[i] <='9')  ++ numeral;
            }
        }

        if (!(facts == 0 && points < 2 && minus < 2 && numeral >= 1)) return "First number not real numbers\n\n" ;

        facts = 0, points = 0, minus = 0, numeral = 0;


    for (int i = 0 ; i < b.length() ; ++i ){                            // проверка второго числа на "вещественность"
        if ( ! (b[i] == '.' || (b[i] >= '0' && b[i] <= '9') || b[i] == '-') ||
             (b[i] >= 'A' &&  b[i] <='Z' && b[i] >='a' && b[i] <='z')) {
            -- facts;

        }else {
            if (b[i] == '.') ++ points;
            if ( b[i] == '-' ) {
                ++ minus;
                if (b[0] != '-' ) --facts;
            }
            if (b[i] >= '0' && b[i] <='9')  ++ numeral;
        }
    }
        if (!(facts == 0 && points < 2 && minus < 2 && numeral >= 1)) return "Second number not real numbers\n\n";

    int over = 0;
    if (a[0] == '0'){ // если начинается с нуля.
        for (int i = 0; i < a.length(); ++i) { // удлалитель нулей в целых числах
            if (a[0] == '0' && (a[i] >= '1' && a[i] <= '9')) {
                over = i;
                break;
            }
        }

        string bufferA; // буфер для переменной а
        for (int i = over; i < a.length(); ++i) {
            bufferA += a[i];
        }
        over = 0;   // обнуление значения
        a = bufferA;
    }   // когда фиксил проблему добавил такую штуку чтобы не заменять все a на a1



    if (b[0] == '0'){  // удлалитель нулей в целых числах
        for (int i = 0; i < b.length(); ++i) {
            if (b[0] == '0' && (b[i] >= '1' && b[i] <= '9')) {
                over = i;
                break;
            }
        }
        string bufferB;  // буффер переменных
        for (int i = over; i < b.length(); ++i) {
            bufferB += b[i];
        }
        b = bufferB; // когда фиксил проблему добавил такую штуку чтобы не заменять все b на bufferB
        over = 0;
    }


    if (a[0] == '-' && b[0] != '-') return "Less\n";           // явно, у числа которое начинаеся с минуса оно меньше
    else if (a[0] != '-' && b[0] == '-') return  "More\n";
    else {

        int lengthOne = a.length() + 1, lengthTwo = b.length() + 1;  // если число целое то по умолчанию точка в конце.
        for (int i = 0; i < a.length() ; ++ i){ // местоположение разделителя первого числа.
            if (a[i] == '.') {
                lengthOne = i + 1; // счет же от нуля идет
                break;
            }
        }
        for (int i = 0; i < b.length() ; ++i){  // местоположение разделителя второго числа.
            if (b[i] == '.') {
                lengthTwo = i + 1; // счет же от нуля идет
                break;
            }
        }
        if (lengthOne > lengthTwo) return "More\n";     // то число которое длинее до точки явно больше.
        else if (lengthOne < lengthTwo) return  "Less\n";
        else {// далее нет разницы что указывать lengthOne или lengthTwo они равны.

            string resultA, resultB;

            if (a[a.length()-1] == '0'){ // если первое число  с точкой, заканчивается на 0 то
                int min = 0;
                bool good = true;
                for (int i = a.length()-1 ; good; -- i){ // подсчет числа на которое нужно сместить а
                    if (a[i] == '0' || a[i] == '.' ){
                        min ++;
                    } else if (a[i] != '0'){
                        good = false;
                    }
                }

                for (int i = 0;i < a.length() - min ; ++i){
                    resultA += a[i];
                }
                a = resultA;

            }

            if (b[b.length()-1] == '0'){ // если второе число с точкой заканчивается на 0
                int min = 0;
                bool good = true;
                for (int i = b.length()-1 ; i > lengthOne - 2 && good; -- i){
                    if (b[i] == '0' || (b[i] == '.')){
                        min ++;
                    }else if (b[i] != '0'){
                        good = false;
                    }
                }
                for (int i = 0;i < b.length() - min ; ++i){
                    resultB += b[i];
                }
                b = resultB;
            }

            for (int i = 0 ;i < lengthOne; ++ i){ // сравнительное мероприятие, каждое число теперь сравниваем до точки
                if (a[i] > b[i]) return  "More!\n";
                else if (a[i] < b[i]) return "Less!\n";
            }
            for (int i = lengthOne; i < a.length() || i < b.length() ; ++ i) { // от точки до конца.
                if (a[i] > b[i]) return " More!!\n";
                else if (a[i] < b[i]) return "Less!!\n";
            }
        }
    }
    return "Equal\n";
}

int main() {
    int answer = 777;
    while (answer != 0){
        cout << "Choose what you need!\n";
        cout << "Enter '1' - Check email.\n";
        cout << "Enter '2' - Check IP\n";
        cout << "Enter '3' - Comparison of long real numbers\n";
        cin >> answer;

        if (answer == 1) {
            string email;
            cout << "Enter email: \n";
            cin.ignore();
            getline(cin,email);

            cout << checkEmail(email);
        }else if (answer == 2) {
                string ip;
                cout << "Enter IP: \n";
                cin.ignore();
                getline(cin, ip);

                cout << checkIP(ip);

        }else if (answer == 3) {
            string longNumber1, longNumber2;
            cout << "Enter first number:\n";
            cin >> longNumber1;

            cout << "Enter second number:\n";
            cin >> longNumber2;

            cout << comparator(longNumber1,longNumber2);

        }else cout << "Try again!\n\a";

    }
    return 0;
}
