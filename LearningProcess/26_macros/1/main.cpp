#include <iostream>
#define  TITLE "Leonid"
//  ^       ^      ^
 //!1       2      3
    //1 - деректива в ней опрееделяется идентификатор - token, он же макрос.
    //2 -  token , название макроса
    //3 - литерал
    // в макросе можно харнить хоть что!


#define UP (1 << 0)
#define DOWN (1 << 2)
#define LEFT (1 << 3)
#define RIGHT (1 << 4)
#define UP_LEFT (UP | LEFT)
#define UP_RIGHT (UP | RIGHT)
#define DOWN_LEFT (DOWN | LEFT)
#define DOWN_RIGHT (DOWN | RIGHT)


int main() {

    char* complex_title = "My name is "  TITLE " i have the gun";
    std::cout << TITLE << std::endl;
    std::cout << complex_title<< std::endl << std::endl;

    int ans;
    std::cout << "Enter command:\n";
    std::cin >> ans;
    switch (ans) {
        case UP:
            std::cout << "UP!\n";
            break;
        case DOWN:
            std::cout << "Down!\n";
            break;
        case RIGHT:
            std::cout << "Right!\n";
            break;
        case LEFT:
            std::cout << "Left!\n";
            break;
        case UP_RIGHT:
            std::cout << "Up left\n";
            break;
        case UP_LEFT:
            std::cout << "Up left!\n";
            break;
        case DOWN_RIGHT:
            std::cout << "Down and right!\n";
            break;
        case DOWN_LEFT:
            std::cout << "Down and left!\n";
            break;
        default:
            std::cout << "Not Found command!\n";
            break;
    }



    return 0;
}
