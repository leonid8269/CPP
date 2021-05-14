#include <iostream>

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7
#define GET(a, b) a ##_## b




int main() {

    std::cout << "Enter number day\n";
    int ans;
    std::cin >> ans;

    std::string day_one ;

    switch (ans) {
        case MONDAY:
            GET(day ,one) = "Monday";
            std::cout << GET(day ,one);
            break;
        case TUESDAY:
            GET(day ,one) = "Tuesday";
            std::cout << GET(day ,one);
            break;
        case WEDNESDAY:
            GET(day ,one) = "Wednesday";
            std::cout << GET(day ,one);
            break;
        case THURSDAY:
            GET(day ,one) = "Thursday";
            std::cout << GET(day ,one);
            break;
        case FRIDAY:
            GET(day ,one) = "Friday";
            std::cout << GET(day ,one);
            break;
        case SATURDAY:
            GET(day ,one) = "Saturday";
            std::cout << GET(day ,one);
            break;
        case SUNDAY:
            GET(day ,one) = "Sunday";
            std::cout << GET(day ,one);
            break;
        default:
            std::cout << "There is no such day of the week!\a\n";
    }
    return 0;
}
