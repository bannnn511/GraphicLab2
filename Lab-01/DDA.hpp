//
//  DDA.hpp
//  Lab-01
//
//  Created by An on 4/16/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef DDA_hpp
#define DDA_hpp

#include <stdio.h>
#include "Header.h"

class DDA {
private:
    int startX;
    int startY;
    int endX;
    int endY;
public:
    void drawLine(float, float, float, float);
};
#endif /* DDA_hpp */
