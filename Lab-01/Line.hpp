//
//  Shape.hpp
//  Lab-01
//
//  Created by An on 4/18/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>
#include "Header.h"

class Line {
public:
    int x1;
    int y1;
    int x2;
    int y2;
//    int& points;

    Line(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    void drawLine();

};
#endif /* Shape_hpp */
