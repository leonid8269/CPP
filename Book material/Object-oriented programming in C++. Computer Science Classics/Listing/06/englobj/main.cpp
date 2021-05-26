//класс как тип данных

#include <iostream>

class distance {
private:
    int feet;
    float inches;
public:
    void setdist(int ft, float in){
        feet = ft;
        inches = in;
    }
    void getdist(){
        std::cout << "\nEnter number feet : ";
        std::cin >> feet;
        std::cout << "\n Enter number inches : ";
        std::cin >> inches;
    }
    void showdist(){
        std::cout << feet << "\'-" << inches <<"\"";
    }
};


int main() {

    distance dis1{}, dis2{};

    dis1.setdist(11,6.25);  // здесь назначаем передаваемыми аргументами
    dis2.getdist(); //здесь ввод через клавиатуру вс ясно тут


    std::cout << "\ndist1 = "; dis1.showdist();
    std::cout << "\ndist2 = "; dis2.showdist();

    return 0;
}
