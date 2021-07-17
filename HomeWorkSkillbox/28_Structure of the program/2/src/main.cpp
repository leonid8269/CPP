#include <conio.h>

#include "../include/ram.h"
#include "../include/cpu.h"
#include "../include/disk.h"
#include "../include/gpu.h"
#include "../include/kbd.h"


int main() {

    do{
        std::cout << "Enter command: \n";
        std::string answer;
        std::cin >> answer;
        if ( answer == "sum" ){
            compute(buffer);
        }else if (answer == "save"){
            save();
        }else if (answer == "load"){
            load();
        }else if (answer == "input"){
            input();
        }else if (answer == "display"){
            output();
        }else if (answer == "exit"){
            break;
        }else{
            std::cout << "Not found command. Try again!\n\a";
        }
    }while(true);

    std::cout << "Bye! Bye!\n";
    std::cout << "Press ENTER\n";
    getch();

    return 0;
}
