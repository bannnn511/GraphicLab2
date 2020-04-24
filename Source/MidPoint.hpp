//
//  MidPoint.hpp
//  Lab-01
//
//  Created by An on 4/18/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef MidPoint_hpp
#define MidPoint_hpp

#include "Header.h"

class MidPoint: Circle {
public:
    MidPoint(int x, int y, int r): Circle(x,y,r) {
    }
    std::vector<Pixel> drawCircle();
    int fCircle(int, int);
};
#endif /* MidPoint_hpp */
