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
    float d=1-2*focal,x1=0,y1=0;
    while(y1<=50)
    {
        putPixel(x1+x, y1+y);
        putPixel(x1+x, -y1+y);
        if(d<0){
            d+=3+2*y1;
        }
        else
        {
            d+=3+2*y1-2*focal;
            x1++;
        }
        y1++;
    }
    d=1/4-2*focal;
    while(x1<=50){
        putPixel(x1+x, y1+y);
        putPixel(x1+x, -y1+y);
        if(d>0){
            d+=-4*focal;
        }
        else{
            d+=2+2*y1-4*focal;
            y1++;
        }
        x1++;
    }
}

