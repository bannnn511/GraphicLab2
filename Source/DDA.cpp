//
//  DDA.cpp
//  Lab-01
//
//  Created by An on 4/16/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

//#include <cstdlib>
#include "DDA.hpp"
#include <unistd.h>


std::vector<Pixel> DDA::drawLine() {
    std::vector<Pixel> data;
    float dX = x2-x1;
    float dY = y2-y1;
    float steps = (abs(dX) > abs(dY)) ? abs(dX) : abs(dY);
    float x =x1;
    float y=y1;
    float xInc = dX/steps;
    float yInc = dY/steps;

    for ( int i = 0; i <= steps; i++) {
        glColor3f(1.0,0,0.0);
        x = x + xInc;
        y = y+ yInc;
        putPixel(x, y);
        data.push_back(Pixel(x, y));
        glEnd();
    }
    return data;
}
