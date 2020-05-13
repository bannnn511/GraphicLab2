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
    std::cout<<"x1: "<<x1<<" x2: "<<x2 <<" y1: "<<y1<<" y2 "<<y2<<std::endl;
}

void Rectangle::scaling(int key) {
    int temp;
    // make x1 and y1 allways smaller
    if (x1>x2) {
        temp = x1;
        x1 = x2;
        x2 = temp;
    }
    
    if (y1>y2) {
        temp = y1;
        y1 = y2;
        y2 = temp;
    }
    
    double det = (x2-x1)*(y2-y1);
    switch (KEY) {
        case Bigger: {
            double newDet = det*110/100;
            double increment = sqrt(newDet/det)/2;
            y1-=increment;
            y2+=increment;
            x1-=increment;
            x2+=increment;
            break;
        }
        case Smaller: {
            double newDet = det *100/110;
            double increment = sqrt(newDet/det)/2;
            x1+=increment;
            x2-=increment;
            y1+=increment;
            y2-=increment;
            break;
        }
        default:
            break;
    }
}
