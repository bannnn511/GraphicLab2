//
//  MidPoint.cpp
//  Lab-01
//
//  Created by An on 4/18/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#include "MidPoint.hpp"
#include "Header.h"

std::vector<Pixel> MidPoint::drawCircle() {
    std::vector<Pixel> data;
    int x0 = r;
    int y0 = 0;
    double p = 1 - r;
    
    RGBColor color;
    color.r = 200;
    color.g = 0;
    color.b = 0;
    
    putPixel(x0+x, y0+y, color);
    data.push_back(Pixel(x0+x,y0+y));
    
    while (x0 >y0) {
        y0++;
        if(p<=0) {
            p += 2*y0 + 1;
        } else {
            x0--;
            p += 2*y0 - 2*x0 +1;
        }
        if (x0<y0) {
            break;
        }
        putPixel(x0+x, y0+y, color);
        data.push_back(Pixel(x0+x,y0+y));
        putPixel(-x0+x, y0+y, color);
        data.push_back(Pixel(-x0+x,y0+y));
        putPixel(x0+x, -y0+y, color);
        data.push_back(Pixel(x0+x,-y0+y));
        putPixel(-x0+x, -y0+y, color);
        data.push_back(Pixel(-x0+x,-y0+y));
        
        if(x0!=y0) {
            putPixel(y0+x, x0+y, color);
            data.push_back(Pixel(y0+x,x0+y));
            putPixel(-y0+x, x0+y,color);
            data.push_back(Pixel(-y0+x,x0+y));
            putPixel(y0+x, -x0+y, color);
            data.push_back(Pixel(y0+x,-x0+y));
            putPixel(-y0+x, -x0+y, color);
            data.push_back(Pixel(-y0+x,-x0+y));
        }
    }
    
    return data;
}

int MidPoint::fCircle(int x, int y) {
    return  x*x + y*y - r*r;
}

bool MidPoint::checkInside(int x1, int y1) {
    if ((x1<x+r) && (x1>x-r) && (y1<y+r) && (y1>y-r)) {
        std::cout<<"Circle inside"<<std::endl;
        return true;
    }
    std::cout<<"Circle outside"<<std::endl;
    return false;
}
