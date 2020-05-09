//
//  Eclipse.hpp
//  Lab-01
//
//  Created by An on 4/21/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef Ellipse_hpp
#define Ellipse_hpp

#include <stdio.h>

class Ellipse {
private:
    int x;
    int y;
    int rA;
    int rB;
public:
    Ellipse(int x, int y, int rA, int rB) {
        this-> x = x;
        this->y = y;
        this->rA = rA;
        this->rB = rB;
    }
    void drawEllipse();
    bool checkInside(int, int);
};

#endif /* Eclipse_hpp */
