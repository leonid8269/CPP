
#include <QTextStream> // подключаем необходимый заголовочный файл

int main() {



   QTextStream out(stdout);

   // Создаем строку типа QString
   QString a = "love";

   // Добавляем текст в конец строки
   a.append(" chess");

   // Добавляем текст в начало строки
   a.prepend("I ");

   // Выводим строку
   out << a << "\n";

   // Выводим количество символов строки
   out << "The a string has " << a.count() << " characters\n" ;

   // Выводим всю строку в верхнем регистре
   out << a.toUpper() << "\n";

   // Выводим всю строку в нижнем регистре
   out << a.toLower() << '\n';

   return 0;
}
