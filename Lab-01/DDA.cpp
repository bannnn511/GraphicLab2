//
//  DDA.cpp
//  Lab-01
//
//  Created by An on 4/16/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

//#include <cstdlib>
#include "DDA.hpp"

int abs (float n) {
    return ( (n>0) ? n : ( n * (-1)));
}

void DDA::drawLine(float startX, float startY, float endX, float endY) {
    float dX = startX - endX;
    float dY = startY - endY;
    float steps = (abs(dX) > abs(dY)) ? abs(dX) : abs(dY);
    
    float xInc = abs(dX)/steps;
    float yInc = abs(dY)/steps;

    for ( int i = 0; i <= steps; i++) {
        glBegin(GL_POINTS);
        glColor3f(1.0,0,0.0);
        glVertex2f(startX, startY);
        startX = startX + xInc;
        startY = startY + yInc;
        glEnd();
        glFlush();
    }
   
}
