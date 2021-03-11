//Задача 2. Средняя этажность
//
//С помощью массивов объявите 5 зданий, каждый элемент которых будет обозначать отдельный
//этаж. Это могут быть совершенно разные здания: фитнес-клуб (2 этажа), магазин (1 этаж), коттедж
//(3 этажа), квартирный дом (15) и небоскрёб (50 этажей). Используя среднее арифметическое
//число, узнайте итоговую этажность вашего “квартала”

#include <iostream>

using std::cout;

int main() {
    int skyscraper[500], hospital[20], administration[5], police[10], opposition[20];
    int average = (sizeof (skyscraper) / sizeof (skyscraper[0]) + sizeof (hospital) / sizeof (hospital[0])+
                  sizeof (administration) / sizeof (administration[0]) + sizeof (police) / sizeof (police[0])
                  + sizeof (opposition) / sizeof (opposition[0])) / 5;

    cout << "Average = " << average << ".\a\n";

    return 0;


}
