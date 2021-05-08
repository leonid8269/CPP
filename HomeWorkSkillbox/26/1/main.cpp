#include <iostream>
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7


int main() {

    std::cout << "Enter number day\n";
    int ans;
    std::cin >> ans;
    switch (ans) {
        case MONDAY:
#undef MONDAY
#define MONDAY "Monday!";
            std::cout << MONDAY;
            break;
        case TUESDAY:
#undef TUESDAY
#define TUESDAY "Tuesday!"
            std::cout << TUESDAY;
            break;
        case WEDNESDAY:
#undef WEDNESDAY
#define WEDNESDAY "Wednesday!"
            std::cout << WEDNESDAY;
            break;
        case THURSDAY:
#undef THURSDAY
#define THURSDAY "Thursday!"
            std::cout << THURSDAY;
            break;
        case FRIDAY:
#undef FRIDAY
#define FRIDAY "Friday!"
        std::cout << FRIDAY;
            break;
        case SATURDAY:
#undef SATURDAY
#define SATURDAY "Saturday!"
            std::cout << SATURDAY;
            break;
        case SUNDAY:
#undef SUNDAY
#define SUNDAY "Sunday"
            std::cout << SUNDAY;
            break;
        default:
            std::cout << "There is no such day of the week!\a\n";
    }

    return 0;
}
