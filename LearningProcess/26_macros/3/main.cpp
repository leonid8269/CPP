#include <iostream>
#define TANK(model, name) model ##_## name


void atata_fuck (int count){
    for (int i = 0; i < count ; ++i)
    std::cout << "Fuck! \n";
}

int main() {

    int atata_hot = 0;
    std::cout << atata_hot << std::endl;
    TANK(atata, hot) = 20;
    std::cout << atata_hot << std::endl;

    TANK(atata,fuck)(50); // работает и с функцией...

    //! так же можно компилировтаь или не компилировать участок кода по устовию
#if 0 /// если будет 1 то скомпилится если 0 то нет
    std::cout << "chyo nado padla! \n";
#endif

    return 0;
}
