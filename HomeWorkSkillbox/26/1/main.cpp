#include <iostream>

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7
#define NAME(x) #x


int main() {

    std::cout << "Enter number day\n";
    int ans;
    std::cin >> ans;

    switch (ans) {
        case MONDAY:
            std::cout << NAME(MONDAY);
            break;
        case TUESDAY:
            std::cout << NAME(TUESDAY);
            break;
        case WEDNESDAY:
            std::cout << NAME(WEDNESDAY);
            break;
        case THURSDAY:
            std::cout << NAME(THURSDAY);
            break;
        case FRIDAY:
            std::cout << NAME(FRIDAY);
            break;
        case SATURDAY:
            std::cout << NAME(SATURDAY);
            break;
        case SUNDAY:
            std::cout << NAME(SUNDAY);
            break;
        default:
            std::cout << "There is no such day of the week!\a\n";
    }
    return 0;
}
