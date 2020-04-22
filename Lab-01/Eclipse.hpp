//
//  Eclipse.hpp
//  Lab-01
//
//  Created by An on 4/21/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef Eclipse_hpp
#define Eclipse_hpp

#include <stdio.h>

class Eclipse {
private:
    int x;
    int y;
    int rA;
    int rB;
public:
    Eclipse(int x, int y, int rA, int rB) {
        this-> x = x;
        this->y = y;
        this->rA = rA;
        this->rB = rB;
    }
    void drawEclipse();
};

#endif /* Eclipse_hpp */
