//
//  Bresenham.cpp
//  Lab-01
//
//  Created by An on 4/17/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#include "Bresenham.hpp"

/// make this global đi an
void putPixel(int x, int y) {
    glBegin(GL_POINTS);
//    glColor3f(0, 1, 0);
    glVertex2f(x, y);
    glEnd();
}
void Bresenham::drawLine(int x1, int y1, int x2, int y2) {
    int dX = x2 - x1;
    int dY = y2 - y1;
    int p = 2*dY - dX;   //initial value
    int const1 = 2*dY;
    int const2 = 2*(dY-dX);
    int x = x1;
    int y = y1;
    glColor3f(0, 1, 0);
    putPixel(x, y);
    
    while(x<x2) {
        if (p <0) {
            p += const1;
        } else {
            p += const2;
            y = y + 1;
        }
        x=x+1;
        putPixel(x, y);
    }
}

void Bresenham::drawLine2(int x1, int y1, int x2, int y2) {
    int p = 2*(y2 - y1);
    int incre = p - (x2 - x1);
    for (int x = x1, y = y1; x <= x2; x++) {
        glColor3f(1, 1, 0);
        putPixel(x, y);
        incre += p;
        if (incre >= 0) {
            y++;
            incre -= 2 * (x2 - y2);
        }
    }
}
    

