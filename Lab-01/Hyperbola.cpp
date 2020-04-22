//
//  Hyperbola.cpp
//  Lab-01
//
//  Created by An on 4/22/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#include "Hyperbola.hpp"
#include "Header.h"

void Hyperbola::drawHyperbola() {
    glColor3f(1, 0.5, 0.5);
       float dx, dy, d1, d2;
       float x1 = 0;
       float y1 = 0;
       
       d1 = rB*rB - (rA*rA*rB) + (0.25 *rA*rA);
       d2 = rB*rB * ((x1+0.5)*(x1+0.5)) +
       ((rA * rA) * ((y1 - 1) * (y1 - 1))) - (rA * rA * rB * rB);
       
       dx = 2*rB*rB*x1;
       dy = 2*rA*rA*y1;
       
       while (dx < dy) {
           putPixel(x1+x, y1+y);
           putPixel(-x1+x, y1+y);
           putPixel(x1+x, -y1+y);
           putPixel(-x1+x, -y1+y);
           
           if(d1<0) {
               x1++;
               dx += 2 * rB * rB;
               d1 += dx + rB * rB;
           } else {
               x1++;
               y1++;
               dx += 2 * rB * rB;
               dy -= 2 * rA * rA;
               d1 += dx - dy + rB * rB;
           }
       }
       
       while (y1 <=100) {
           putPixel(x1+x, y1+y);
           putPixel(-x1+x, y1+y);
           putPixel(x1+x, -y1+y);
           putPixel(-x1+x, -y1+y);
           
           if (d2>0) {
               y1++;
               dy -= (2 * rA * rA);
               d2 += rA * rA - dy;
           } else {
               y1++;
               x1++;
               dx += 2 * rB * rB;
               dy -= 2 * rA * rA;
               d2 += dx - dy - rA*rA;
           }
       }
}
