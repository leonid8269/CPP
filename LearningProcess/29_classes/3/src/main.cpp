#include <iostream>

class PlaneControl {

private:
    double leftAileron{};
    double rightAileron{};
    double elevator{};

public:
    void turn_left(){             //! а эти методы называются сеттеры!
        leftAileron -= 30;
        rightAileron += 30;
    }

    void turn_right(){
        leftAileron +=30;
        rightAileron -=30;
    }

    void set_elevator(double value){
        if (value < -30 ) elevator = -30;
        if (value > 30) elevator = 30;
        if (value == elevator) return;
    }

    //!как узнать значение поля \приват... называют гетерами такие методы

    double get_right_aileron() const{
        return rightAileron;
    }
    double get_left_aileron() const{
        return leftAileron;
    }
    double get_elevator() const{
        return elevator;
    }


};


int main() {
    PlaneControl* planeControl = new PlaneControl();

    planeControl ->set_elevator(40);

    std::cout << "right = " << planeControl->get_right_aileron() << " Left = " << planeControl->get_left_aileron() <<
                " elevator = " << planeControl->get_elevator() << std::endl;

    delete planeControl;
    planeControl = nullptr;

    return 0;
}
