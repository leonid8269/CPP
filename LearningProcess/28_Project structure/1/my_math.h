#pragma once
#include <cmath>   //atan()

double pi (){
    return atan(1.0) * 4;
}

double circumference(double radius){
    return 2 * pi() * radius;
}