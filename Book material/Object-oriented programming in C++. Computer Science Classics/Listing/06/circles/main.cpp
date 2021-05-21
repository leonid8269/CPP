#include <iostream>
#include "msoftcon.h"

class circle{
protected:
    int xCo, yCo;
    int radius;
    color fillcolor;
    fstyle fillstyle;
public:
    void set(int x, int y, int r, color fc, fstyle fs){
        xCo = x;
        yCo = y;
        radius = r;
        fillcolor = fc;
        fillstyle = fs;
    }
    void draw(){
        set_color(fillcolor);

    }

};





int main() {


    return 0;
}
