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
