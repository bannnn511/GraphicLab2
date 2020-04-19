//
//  Header.h
//  Lab-01
//
//  Created by An on 4/16/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include "glew.h"
#include "glfw3.h"

#include "Line.hpp"
#include "DDA.hpp"
#include "Bresenham.hpp"
#include "MidPoint.hpp"
#include <iostream>
#include <cmath>

void groundTruth(int, int, int, int);
void circleTruth(int, int ,int);
void putPixel(int, int);
#endif /* Header_h */

