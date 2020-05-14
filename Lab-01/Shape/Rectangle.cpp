//
//  Rectangle.cpp
//  Lab-01
//
//  Created by An on 5/2/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#include "Rectangle.hpp"
#include "Header.h"

void Rectangle::drawRectangle() {
    Bresenham bsh = Bresenham(x1, y1, x2, y1);
    bsh.drawLine();
    bsh = Bresenham(x2,y1,x2,y2);
    bsh.drawLine();
    bsh = Bresenham(x1, y2, x2, y2);
    bsh.drawLine();
    bsh = Bresenham(x1, y1, x1, y2);
    bsh.drawLine();
}

Pixel Rectangle::getCenterPoint() {
    int x = (x1+x2)/2;
    int y = (y1+y2)/2;
    return Pixel(x,y);
}

bool Rectangle::checkInside(int x, int y) {
    int xMin = x1 > x2 ? x2 : x1;
    int xMax = x1 > x2 ? x1 : x2;
    int yMin = y1 > y2 ? y2 : y1;
    int yMax = y1 > y2 ? y1 : y2;
    
    if ((x>xMin) && (x<xMax) && (y<yMax) && (y>yMin)) {
        std::cout<<"Rectangle inside"<<std::endl;
        return true;
    }
    std::cout<<"Rectangle outside"<<std::endl;
    return false;
}

Rectangle Rectangle::transformation() {
    if (KEY == Left || KEY == Right || KEY == Up || KEY == Down) {
        translation(KEY);
    }
    if (KEY == Bigger || KEY == Smaller) {
        scaling(KEY);
    }
    
    if (KEY == Lockwise || KEY == CounterLockwise) {
        rotation(KEY);
    }
     std::cout<<"x1: "<<x1<<" x2: "<<x2 <<" y1: "<<y1<<" y2 "<<y2<<std::endl;
    return Rectangle(x1,y1,x2,y2);
}

void Rectangle::translation(int key) {
    switch (key) {
        case Left:
            x1--;
            x2--;
            break;
        case Right:
            x1++;
            x2++;
            break;
        case Up:
            y1++;
            y2++;
            break;
        case Down:
            y1--;
            y2--;
            break;
        default:
            break;
    }
}

void Rectangle::scaling(int key) {
    double increment = 1;
    switch (key) {
        case Bigger: {
            increment = 1.1;
            break;
        }
        case Smaller: {
            increment = 0.90909091;
            break;
        }
        default:
            break;
    }
    y1*=increment;
    y2*=increment;
    x1*=increment;
    x2*=increment;
}

void Rectangle::rotation(int key) {
    double xold1 = x1;
    double xold2 = x2;
    double yold1 = y1;
    double yold2 = y2;
    
    double c = cos(angle *3.14/180);
    double s = sin(angle *3.14/180);
    switch (key) {
        case Lockwise:
            x1 = xold1*c + yold1*s;
            y1 = -xold1*s + yold1*c;
            x2 = xold2*c + yold2*s;
            y2 = -xold2*s + yold2*c;
            break;
            
        case CounterLockwise:
            x1 = xold1*c - yold1*s;
            y1 = xold1*s + yold1*c;
            x2 = xold2*c - yold2*s;
            y2 = xold2*s + yold2*c;
            break;
    }
    angle++;
}
