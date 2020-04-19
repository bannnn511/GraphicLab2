//
//  MidPoint.hpp
//  Lab-01
//
//  Created by An on 4/18/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef MidPoint_hpp
#define MidPoint_hpp

#include <stdio.h>

class MidPoint {
private:
    int r;
    int x;
    int y;
public:
    MidPoint(int x, int y, int r) {
        this-> x = x;
        this-> y = y;
        this-> r = r;
    }
    void drawCircle();
    int fCircle(int, int);
};
#endif /* MidPoint_hpp */
