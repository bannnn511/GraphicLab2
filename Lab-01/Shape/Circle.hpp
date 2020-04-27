//
//  Circle.h
//  Lab-01
//
//  Created by An on 4/21/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef Circle_h
#define Circle_h

#include "Header.h"

class Circle {
public:
    int x;
    int y;
    int r;

    Circle(int x, int y, int r) {
        this->x = x;
        this->y = y;
        this->r = r;
    }
    
    void drawCircle();
};

#endif /* Circle_h */
