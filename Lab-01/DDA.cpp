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
int abs (float n) {
    return ( (n>0) ? n : ( n * (-1)));
}

void DDA::drawLine(float x1, float y1, float x2, float y2) {
    float dX = x1 - x2;
    float dY = y1 - y2;
    float steps = (abs(dX) > abs(dY)) ? abs(dX) : abs(dY);
    
    float xInc = abs(dX)/steps;
    float yInc = abs(dY)/steps;

    for ( int i = 0; i <= steps; i++) {
        glBegin(GL_POINTS);
        glColor3f(1.0,0,0.0);
        glVertex2f(x1, y1);
        x1 = x1 + xInc;
        y1 = y1 + yInc;
        glEnd();
        glFlush();
    }
   
}
