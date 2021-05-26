#include <iostream>
#include "../include/surg_op.h"


int main() {
    do {
        std::string answer{};
        std::cout << "Enter command:\n";
        std::cin >> answer;

        coordinate step[4];
        if(answer == "scalpel" && (!stat[ONE_STEP] && !stat[TWO_STEP] &&
                  !stat[THREE_STEP] && !stat[FOUR_STEP]) ) {

            scalpel(step[0]);

        }else if(answer == "hemostat" && stat[ONE_STEP] && (!stat[TWO_STEP] &&
                  !stat[THREE_STEP] && !stat[FOUR_STEP]) ){

            hemostat(step[1]);

        }else if(answer == "tweezers" && (stat[ONE_STEP] && stat[TWO_STEP]) &&
                 (!stat[THREE_STEP] && !stat[FOUR_STEP]) ){

            tweezers(step[2]);

        }else if (answer == "suture"  && stat[ONE_STEP] && stat[TWO_STEP] && stat[THREE_STEP] &&
                (!stat[FOUR_STEP]) ){

            suture(step[3],step[0]);

        }else {
            std::cout << "\nError, try again!\n\a";
        }
    }while (!stat[FOUR_STEP]); // пока статус последний операции не выполнен

    return 0;
}
