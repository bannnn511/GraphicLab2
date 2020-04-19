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

class DDA: Line {
public:
    DDA(int x1, int y1, int x2, int y2): Line(x1,y1,x2,y2) {
        
    };
    void drawLine();
};
#endif /* DDA_hpp */
