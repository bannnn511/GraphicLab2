//
//  Bresenham.cpp
//  Lab-01
//
//  Created by An on 4/17/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#include "Bresenham.hpp"


std::vector<Pixel> Bresenham::drawLine() {
//    int dX = abs(x2 - x1);
//    int dY = abs(y2 - y1);
//    int p = 2*dY - dX;   //initial value
//    int const1 = 2*dY;
//    int const2 = 2*(dY-dX);
//    int x = x1;
//    int y = y1;
//    glColor3f(0, 1, 0);
//    putPixel(x, y);
//
//    while(x<x2) {
//        if (p <0) {
//            p += const1;
//        } else {
//            p += const2;
//            if (y1<y2) {
//                y = y + 1;
//            } else {
//                y = y -1;
//            }
//        }
//        x=x+1;
//        putPixel(x, y);
//    }
    std::vector<Pixel> data;
    glColor3f(0, 1, 0);
    if (abs(y2-y1) < abs(x2-x1)) {
        if (x1>x2) {
            data = drawLineLow(x2,y2,x1,y1);
        } else {
            data = drawLineLow(x1,y1,x2,y2);
        }
    } else {
        if (y2>y1) {
            data = drawLineHigh(x1,y1,x2,y2);
        } else {
            data = drawLineHigh(x2,y2,x1,y1);
        }
    }
    return data;
}

std::vector<Pixel> Bresenham::drawLineLow(int x1, int y1, int x2, int y2) {
    std::vector<Pixel> data;
    int dX = x2 -x1;
    int dY = y2 -y1;
    int yi = 1;
    if (dY<0) {
        yi = -1;
        dY = -dY;
    }
    int D = 2 * dY - dX;
    int y = y1;
    RGBColor color;
    color.r = 200;
    color.g = 0;
    color.b = 0;
    for (int x = x1; x<=x2; x++) {
        putPixel(x, y, color);
        data.push_back(Pixel(x, y));
        if (D > 0) {
            y += yi;
            D = D - 2*dX;
        }
        D = D + 2*dY;
    }
    return data;
}

std::vector<Pixel> Bresenham::drawLineHigh(int x1, int y1, int x2,int y2) {
    std::vector<Pixel> data;
    int dX = x2 -x1;
    int dY = y2 -y1;
    int xi = 1;
    if (dX<0) {
        xi = -1;
        dX = -dX;
    }
    int D = 2 * dX - dY;
    int x = x1;
    
    RGBColor color;
     color.r = 200;
    color.g = 0;
    color.b = 0;
    
    for (int y = y1; y<=y2; y++) {
        putPixel(x, y, color);
        data.push_back(Pixel(x, y));
        if (D > 0) {
            x += xi;
            D = D - 2*dY;
        }
        D = D + 2*dX;
    }
    return data;
}

