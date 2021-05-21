#include <iostream>
class part{
private:
    int modelnumber{};
    int partnumber{};
    double cost{};

public:
    void setpart(int mn, int pn, float c){
        modelnumber = mn;
        partnumber = pn;
        cost = c;
    }
    void showpart(){
        std::cout << "Model: " << modelnumber << '\n' <<
                     "Detail: " << partnumber << '\n' <<
                     "Cost: $" << cost << '\n';
    }
};

int main() {
    part part1;
    part1.setpart(580, 300, 55.5);
    part1.showpart();


    return 0;
}
