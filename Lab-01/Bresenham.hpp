//
//  Bresenham.hpp
//  Lab-01
//
//  Created by An on 4/17/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef Bresenham_hpp
#define Bresenham_hpp

#include <stdio.h>
#include "Header.h"

class Bresenham: Line {
private:
    void drawLineLow(int x1, int y1, int x2, int y2);
    void drawLineHigh(int x1, int y1, int x2, int y2);
public:
    Bresenham(int x1, int y1, int x2, int y2):Line(x1, y1, x2, y2) {
        
    }
    void drawLine();
    
};
#endif /* Bresenham_hpp */
