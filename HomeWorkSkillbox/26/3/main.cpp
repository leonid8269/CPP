#include <iostream>

#define SPRING 1
#define SUMMER 1
#define AUTUMN 1
#define WINTER 1

#define NAME(x) #x


#if ( SPRING ) // в скобки введи макрос сезона который хочешь увидить
int main(){

    std::cout << NAME(SPRING); // в скобки введи макрос сезона который хочешь увидить

    return 0;
}

#endif