#include <iostream>

class PlaneControl {
private:
    double leftAileron{};
    double rightAileron{};
    double elevator{};

public:
    void turn_left(){
        leftAileron -= 30;
        rightAileron += 30;
    }

    void turn_right(){
        leftAileron +=30;
        rightAileron -=30;
    }

    void set_elevator(){

    }

};


int main() {
    PlaneControl* planeControl = new PlaneControl();

    delete planeControl;
    planeControl = nullptr;

    return 0;
}
