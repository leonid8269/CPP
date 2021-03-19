#include <iostream>
#include <string> // заголовочный файл для std::to_string

using namespace  std;


string char_to_string (char& a){  // символьный тип в строковый
    string test = string(1,a); //
    return test;
}

string int_array_to_string (int arr[5]) // аргумент интовый массив
{
    string result = " ";    // строка результат
    for (int i = 0; i < 5; ++i) // цикл для инициализации строки
    {
        result += + " " + to_string(arr[i]);
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

int main() {
    int room = 36;
    string text = to_string(room); // преобразвание цифр в строку с переносом содержания..
    cout << text << endl; // покажет 36. а не номер по ASCII

    cout << bool_to_string(false) << endl; // вернет строку фолс

    int array[5] = {1, 2, 3, 4, 5}; // массив необходимый для конверции
    cout << int_array_to_string(array); // возвращаемое значение







    return 0;
}
