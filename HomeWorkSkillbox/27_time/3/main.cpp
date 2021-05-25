#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>

class timer{

private:
    time_t general{};
    tm tm_t = *std::localtime(&general);

public:
    void set_timer(){
        std::cout << "Enter MM:SS\n";
        std::cin >> std::get_time(&tm_t, "%M:%S");

    }

    void timer_go() {

        time_t stop = time(nullptr);
        uint32_t save = time(nullptr);

        general = time(nullptr);
        general += ( ( 60 * tm_t.tm_min ) + tm_t.tm_sec );

        bool flag = false;
        for (  ;stop != general ;stop = time(nullptr) ) {
            time_t buf = general - stop;
            std::tm tm_buf = *std::localtime(&buf);
            if (stop != save){
                save = stop;
                flag = true;
            }

            if (flag){
                std::cout << "Time left [Min:sec]:  " <<
                          tm_buf.tm_min << ':' << tm_buf.tm_sec << "  \n";
                flag = false;
            }
        }
        std::cout << "DING! DING! DING!\n";
    }
};

int main() {
    timer one;
    one.set_timer();
    one.timer_go();

    return 0;
}
