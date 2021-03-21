/*
 * Надо реализовать цифровой спидометр автомобиля.
 * Сама модель автомобиля, которую нужно будет воссоздать весьма проста.
 * Начальная скорость - 0 км/ч.
 * Пользователь вводит в стандартный ввод разницу (дельту) в скорости и
 * результирующая скорость показывается на спидометре в стандартный вывод.
 * Так происходит до той поры, пока машина снова не остановится,
 * т.е. пока скорость не станет меньше или равна нулю
 * (сравнение должно происходить с дельтой в 0.01).
 * Диапазон возможных значений скорости машины от 0 до 150 км/ч.
 * Сам показатель спидометра, вместе с единицами измерения,
 * требуется записывать в отдельную строку-буфер,
 * которая потом и будет показываться на экране. Точность отображения скорость до 0.1 км/ч.
 *
 *
 *
 * */


#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>


using namespace std;

enum border{
    MIN_SPEED,
    MAX_SPEED = 150
};

void speedWiew (string& speed, double delta, bool& unStop){
    double number = stod(speed);
    number += delta;

    if (number >= MAX_SPEED) {
        cout << "Your car has reached maximum speed!! Slow down!!\n\a";
        number = 150;
    }
    char wiew[100];
    sprintf(wiew, "Car speed: %.1f %s ", number, "Km\\h" );

    if (number > MIN_SPEED) cout << wiew << endl ; // показвывать скорость есл она больше минимальной
    else if (number <= MIN_SPEED) unStop = false;

    speed = to_string(number);
}

void process(string& bufSpeed, double& deltaSpeed, bool& unStop){
    cout << "Car speed: 0.0 Km\\h \n";
    do {
        cout << "Enter delta:\n";
        cin >> deltaSpeed;
        speedWiew(bufSpeed, deltaSpeed, unStop);    // показатель спидометра.

        if (!unStop) {
            cout << "Our car stopped, end of the Program\n";
        }

    }while (unStop);
}


int main() {
    string bufSpeed = "0";
    double deltaSpeed = 0;
    bool unStop = true;

    process(bufSpeed, deltaSpeed, unStop);

    return 0;
}
