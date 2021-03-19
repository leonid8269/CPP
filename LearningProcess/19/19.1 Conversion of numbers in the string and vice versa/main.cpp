#include <iostream>
#include <string> // заголовочный файл для std::to_string
#include <sstream> // для приминения класса stringstream, форматирование строк.
#include <cstdio> //


using namespace  std;

//_________________________________________________________________________________

string char_to_string (char& a){  // символьный тип в строковый
    string test = string(1,a); //
    return test;
}

string int_array_to_string (int arr[5]) // аргумент интовый массив
{
    string result = "";    // строка результат
    for (int i = 0; i < 5; ++i) // цикл для инициализации строки
    {
        result +=  + " " + to_string(arr[i]);
    }

    return result; // возвращает строку
}


string bool_to_string ( bool logical) // Преобразование буля в стринг.
{
    if (logical)
    {
        return "true"; // вернет строку Тру
    }
    else
    {
        return "false"; // вернет строку фолс
    }

}


//_________________________________________________________________________________

int string_stoi (string& num)
{
    int room = stoi(num);
    return room;
}

double stod_string (string text)
{
    double r = 5.84;
    double pi = stod(text); // парсинг строки в дабл...
    double  l = 2 * pi * r;
    return l;
}

bool bool_sto(string& text){ // возвращает true если выполняются эти устовия
    return text == "no" || text == "true" || text == "1"; // "Эти" условия
}

//____________________________________________________________________________________

void Robert_Smith(){ // конкатенация строки
    std::stringstream text; // класс stringstream, позволяет связать поток ввода-вывода со строкой в памяти.  Всё, что выводится в такой поток, добавляется в конец строки;
                            // всё, что считыватся из потока — извлекается из начала строки.

    string name = "Robert";
    int age = 65;
    double height = 1.76;
    text << " Name: " << name << " Age = " << age << " Height = " << height;  // все написанное таким образом соединяется в text

    cout << text.str() << endl;  // вывод только чепез .str();

    string dummy;

    text >> dummy >> name >> dummy >> age >> dummy >> height;

    cout << " Name: " << name << " Age = " << age << " Height = " << height << endl; // для посоставления

}

void leonid(){ // язык С, более низкоуровневый подход...
    char text[100];
    sprintf(text, "Name: %s, Age: %i, Height: %.2f, Hits: %f%%", "Leonid", 25, 1.90, 55.5 );  // важен порядок записи

    cout << text;  // выводим что получилось из этого всего)
}


int main() {

    // В строковый из разных...
    int room = 36;
    string text = to_string(room); // преобразвание цифр в строку с переносом содержания..
    cout << text << endl; // покажет 36. а не номер по ASCII

    cout << bool_to_string(false) << endl; // вернет строку фолс

    int array[5] = {1, 2, 3, 4, 5}; // массив необходимый для конверции
    cout << int_array_to_string(array) << endl; // возвращаемое значение

    char s = 't';               // преобразивание чар в стринг
    cout << char_to_string(s) << endl;

    // из строкового типа в другие...

    // жаргонные выражения:
    // еще называют распарсить строку в...
    // парсинг строки...

    string roo = "56"; // парсинг строки в целочисленный тип
    cout << string_stoi(roo) << endl;

    string pi = "3.14159265358979328463"; // число ПИ
    cout << stod_string(pi)<< endl;     // парсинг стрки в дабл

    /* stoi() - Convert string to integer (function template )
     * stol() - Convert string to long int (function template )
     * stoul() - Convert string to unsigned integer
     * stoll() - Convert string to long long
     * stoull() - Convert string to unsigned long long
     * stof() - Convert string to float
     * stod() - Convert string to double
     * stold() - Convert string to long double
     * */
    string one = "on";
    cout << bool_sto(one) << endl;

    //________________________________________________________________
    Robert_Smith(); // конкатенация
    leonid();



    return 0;
}
