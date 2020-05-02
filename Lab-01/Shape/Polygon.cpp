//
//  Polygon.cpp
//  Lab-01
//
//  Created by An on 5/2/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#include "Polygon.hpp"
#include "Header.h"

void Polygon::drawPolygon() {
    std::vector<Pixel>::iterator pt;
    
    Mouse *mouse = mouse->getInstance();
    Pixel pt1 = Pixel(mouse->getXorigin(), mouse->getYorigin());
    for (pt = pts.begin(); pt != pts.end(); pt++) {
        if (pt1.x!=pt->x && pt1.x!= pt->y) {
            Bresenham bsh = Bresenham(pt1.x, pt1.y, pt->x, pt->y);
            bsh.drawLine();
        }
        pt1.x = pt->x;
        pt1.y = pt->y;
    }
}

void Polygon::addPoint(Pixel x) {
    pts.push_back(x);
}
