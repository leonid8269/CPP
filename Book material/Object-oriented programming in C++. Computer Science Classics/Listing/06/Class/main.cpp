#include <iostream>

class smallobj{ // опрределил класс
private:                                // не доступен все класса!
    int somedata; // поле класса в нем садержаться данные класса

public:             // доступен вне класса в нем содержаться методы класса
    void setdata(int d) { // метод класса, изменябщий значение поля
    somedata = d;
    }
    void showdata(){ //метод класса отображающий значение поля
        std::cout << "The field value is equal = " << somedata << std::endl;
    }
}; // подобно структуре, тело заключено в {} и после ;


int main() {

    smallobj s1{}, s2{}; // отпределение 2х объектов класса

    s1.setdata(1066); //! вызов метода \setdata
    s2.setdata(666);

    s1.showdata(); //!вызов метода \showdata
    s2.showdata();

    return 0;
}
