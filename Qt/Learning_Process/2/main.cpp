//Строки и класс Qstring

#include <QCoreApplication>



int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);


    //Использование несколько базовых методов класса QString. в этом нам поможет класс QTextStream
    QTextStream out(stdout); // класс  с удобным интерфесом для записи/чления текстовых данных

    QString text = "Hello .el";  // создание строки типа QString

    text.append(" How are you?"); //Добавить текст в конец строки

    text.prepend("Ops. "); // добавляем текст в начало строки.

    out << text  << '\n'; //выводим на экран

    out << "The a string has " << text.count() << " Characters\n"; // .count метод возвращающий кол-во символов

    out << text.toUpper() << '\n'; // вывести текст в верхнем регистре
    out << text.toLower() << '\n'; // выводим в нижнем регистре







    return a.exec();
}
