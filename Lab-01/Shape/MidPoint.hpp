//
//  MidPoint.hpp
//  Lab-01
//
//  Created by An on 4/18/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef MidPoint_hpp
#define MidPoint_hpp

#include <vector>
#include "../Pixel.cpp"

class MidPoint {
private:
    int x;
    int y;
    int r;
public:
    MidPoint(int x, int y, int r) {
        this->x = x;
        this->y = y;
        this->r = r;
    }
    std::vector<Pixel> drawCircle();
    int fCircle(int, int);
//    Pixel centerMidpoint();
    bool checkInside(int, int);
};

#endif /* MidPoint_hpp */
