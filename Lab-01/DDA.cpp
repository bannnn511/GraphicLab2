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


void DDA::drawLine() {
    float dX = x2-x1;
    float dY = y2-y1;
    float steps = (abs(dX) > abs(dY)) ? abs(dX) : abs(dY);
    
    float xInc = dX/steps;
    float yInc = dY/steps;

    for ( int i = 0; i <= steps; i++) {
        glBegin(GL_POINTS);
        glColor3f(1.0,0,0.0);
        x1 = x1 + xInc;
        y1 = y1 + yInc;
        glVertex2f(x1, y1);
        glEnd();
        glFlush();
    }
   
}
