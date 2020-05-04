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
