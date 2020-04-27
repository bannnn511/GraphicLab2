//
//  Parabola.hpp
//  Lab-01
//
//  Created by An on 4/22/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef Parabola_hpp
#define Parabola_hpp

#include <stdio.h>
#include "Header.h"

class Parabola {
private:
    int x;
    int y;
    double focal;
public:
    Parabola(int x, int y, double focal) {
        this->x = x;
        this->y = y;
        this->focal = focal;
    }
    
    void drawParabola();
};
#endif /* Parabola_hpp */
