#include <iostream>
#include "../include/surg_op.h"


int main() {
    point step[2+1+1+2];// 2 координаты в начале, поcле 2 по одной и в конце две

    do {
        std::string answer{};
        std::cout << "Enter command:\n";
        std::cin >> answer;

        if(answer == "scalpel" && (!stat[Step::ONE] && !stat[Step::TWO] &&
                  !stat[Step::THREE] && !stat[Step::FOUR]) ) {

            scalpel(step[0], step[1]);

        }else if(answer == "hemostat" && stat[ONE] && (!stat[TWO] &&
                  !stat[Step::THREE] && !stat[Step::FOUR]) ){

            hemostat(step[2]);

        }else if(answer == "tweezers" && (stat[Step::ONE] && stat[Step::TWO]) &&
                 (!stat[Step::THREE] && !stat[Step::FOUR]) ){

            tweezers(step[3]);

        }else if (answer == "suture"  && stat[Step::ONE] && stat[Step::TWO] && stat[Step::THREE] &&
                (!stat[Step::FOUR]) ){

            suture(step[4],step[5],step[0],step[1]);

        }else {
            std::cout << "\nError, try again!\n\a";
        }
    }while (!stat[Step::FOUR]); // пока статус последний операции не выполнен


    std::cout << "The operation was successful\n";

    return 0;
}
