//
//  Hyperbola.hpp
//  Lab-01
//
//  Created by An on 4/22/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef Hyperbola_hpp
#define Hyperbola_hpp

#include <stdio.h>
#include "Header.h"

class Hyperbola {
private:
    int x;
    int y;
    int rA;
    int rB;
public:
    Hyperbola(int x, int y, int rA, int rB) {
        this->x = x;
        this->y = y;
        this->rA = rA;
        this->rB = rB;
    }
    
    void drawHyperbola();
};

#endif /* Hyperbola_hpp */
