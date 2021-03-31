#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>

using namespace std;

int main() {
    time_t rawtime; // скрока в секундах

    time ( & rawtime );

    stringstream time;
    time << ctime (&rawtime);

    return 0;
}
