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
    int p = 1 - r;
    
    putPixel(x0+x, y0+y);
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
        putPixel(x0+x, y0+y);
        data.push_back(Pixel(x0+x,y0+y));
        putPixel(-x0+x, y0+y);
        data.push_back(Pixel(x0+x,y0+y));
        putPixel(x0+x, -y0+y);
        data.push_back(Pixel(x0+x,y0+y));
        putPixel(-x0+x, -y0+y);
        data.push_back(Pixel(x0+x,y0+y));
        
        if(x0!=y0) {
            putPixel(y0+x, x0+y);
            data.push_back(Pixel(x0+x,y0+y));
            putPixel(-y0+x, x0+y);
            data.push_back(Pixel(x0+x,y0+y));
            putPixel(y0+x, -x0+y);
            data.push_back(Pixel(x0+x,y0+y));
            putPixel(-y0+x, -x0+y);
            data.push_back(Pixel(x0+x,y0+y));
        }
    }
    
    return data;
}

int MidPoint::fCircle(int x, int y) {
    return  x*x + y*y - r*r;
}
