#include <iostream>
#include <iomanip> // for using  std::setw


void overFlow() {
    //!Overflow:
    int first = 1500000000;
    unsigned int second = 1500000000;

    first = (first * 2) / 3;
    second = (second * 2) / 3;

    std::cout << "signed variable (OVERFLOW) = " << first << std::endl
              << "unsigned variable = " << second << "\n\n\n";

}

void setw(){
    const uint8_t size_setw_one =  9;
    const uint8_t size_setw_two =  5;

    uint16_t a = 1231, b = 5, c = 2;

    std::cout  << "Moscow = " << a << std::endl <<
               "nvkz = " << b << std::endl <<
               "zero = " << c  << "\n\n\n";
    std::cout << std::setw(size_setw_one) << "Moscow = " << std::setw (size_setw_two) << a << std::endl <<
              std::setw(size_setw_one) <<"nvkz = " << std::setw (size_setw_two)<< b << std::endl <<
              std::setw(size_setw_one) <<"zero = " << std::setw (size_setw_two) << c  << "\n\n\n";


}


void removing_a_constant (const int* i1, const int& i2){
    int *p;
    std::cout << "Before = " << *i1 << "\n";
    p = const_cast<int*>(i1);
    *p = 33;
    std::cout << "After = " << *i1 << '\n';
    *p = 23;
    std::cout << "After-after = " << *i1 << '\n';

}


void transforming_types(){

    int one = 7;
    float two = 11.5f;
    float total = one * two;

    std::cout << total;

    /*!
     * иерархия типов данных
     * long double  - высший
     * double
     * float
     * long
     * int
     * short
     * char         - низший
     * */


    //! явное преобразивание типов!

    int8_t a = 122;
    char b = static_cast<char>(a);
    std::cout << "\n\n (explicit transformation of types!) a (char) = " << a << "\n\n\n\n" ;

    //! вне учебный материал:
    //!квалификаторы volatile и const (cv - квалификаторы: )
    /*! const защищает от изменения
     *
     *  volatile - значение переменной может меняться без явного выполнения присваивания
     *  Это обеспечивает защиту от оптимизации компилятором операций с данной переменной.
     *
     *  const_cast  - удаляет или присваивает квалификаторы const или volatile
     *
     *  примеры:
     */

    //снятие константности:
    int i = 3;
    int* pi = &i;
    removing_a_constant(pi,23);
}



int main() {

    setw();

    overFlow();

    transforming_types();



    return 0;
}
