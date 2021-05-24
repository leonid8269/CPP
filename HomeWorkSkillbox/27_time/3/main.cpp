#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>



class timer{

private:
    time_t general = time(nullptr);
    tm tm_t = *std::localtime(&general);

public:
    void set_timer(){
        std::cout << "Enter MM:SS\n";
        std::cin >> std::get_time(&tm_t, "%M:%S");
        general += (60 * tm_t.tm_min) + tm_t.tm_sec;
    }

    void timer_go(){
        time_t stop{}, buf{};
        uint32_t save = time(nullptr);
        bool flag = false;
        do {
            stop = time(nullptr);
            buf = general - stop;
            std::tm tm_buf = *std::localtime(&buf);
            if (stop != save) {
                save = stop;
                flag = true;
            }
            if (flag) {
                std::cout << "Time left [Min:sec]:  " <<
                          tm_buf.tm_min << ':' << tm_buf.tm_sec << "  \n";
                flag = false;
            }
        }while(stop < general);

        std::cout << "DING! DING! DING!\n";
    }

};


int main() {

    timer one;
    one.set_timer();
    one.timer_go();

    return 0;
}
