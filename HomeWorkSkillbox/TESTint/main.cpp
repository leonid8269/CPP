#include <iostream>

#define WORD ""
#define NAME(x) #x

int main(){

    std::cout << NAME(WORD);
}