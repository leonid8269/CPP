#include <iostream>

struct robot_t{
    int32_t health;
    int32_t damage;
    int32_t speed;


    void attack(){
        std::cout << "Attack = " << damage << "\n";
    }

    void take_damage(){
        std::cout << "Take damage = " << health << "\n";

    }

    void move(){
        std::cout << "Moving = " << speed << '\n';
    }

};


int main() {

    // robot_t robot{10,20,50};
    // robot.attack();

    robot_t* robot = new robot_t {05, 100,10}; //! создание обьекта в куче!
    robot->attack();

    delete robot;//! удаление из кучи


    return 0;
}
