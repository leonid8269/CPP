#include <iostream>

#define WORD "Hello "
#define OUTER(...) WORD #__VA_ARGS__

int main(){



    std::cout << OUTER(lol) << '\n';
    std::cout << OUTER(hg) << '\n';
}