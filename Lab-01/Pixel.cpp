//
//  Pixel.cpp
//  Lab-01
//
//  Created by An on 4/24/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#include <stdio.h>

#ifndef pixel
#define pixel

struct Pixel {
    int x;
    int y;
    
    Pixel(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

#endif
