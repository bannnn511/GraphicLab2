//
//  Parabola.cpp
//  Lab-01
//
//  Created by An on 4/22/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#include "Parabola.hpp"

void Parabola::drawParabola() {
    glColor3f(0.5, 1, 0.5);
    int x1, y1, d, p2, p4;
    double focus = 4*focal;
    float p = 1/focus;
    
    int incre =0;
    int bound = 200;
    if (p > 0) {
        incre++;
    } else {
        incre--;
        bound = -200;
    }
    
    p2 = 2*p;
    p4 = 2*p2;
    x1 = 0;
    y1 = 0;
    d = 1-p;
    
    while((y1<p) && (x1<= bound)) {
        putPixel(x1+x, y1+y);
        putPixel(x1+x, -y1+y);
//        putPixel(-y1+y, x1+x);
//        putPixel(y1+y, x1+x);
        if (d>=0) {
            x1+=incre;
            d -= p2;
        }
        y1+=incre;
        d += 2*y1 +1;
    }
    if (d == 1) {
        d = 1- p4;
    } else {
        d = 1-p2;
    }
    
    while (x1 <=bound) {
        putPixel(x1+x, y1+y);
        putPixel(x1+x, -y1+y);
//        putPixel(-y1+y, x1+x);
//        putPixel(y1+y, x1+x);
        if (d<=0) {
            y1+=incre;
            d += 4*y1;
        }
        x1+=incre;
        d -= p4;
    }
    
}
