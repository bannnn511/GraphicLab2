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
    
    if (pts.size()<=2) {
        return;
    }
    for (size_t i = 0; i <= pts.size(); i++) {
        if (i+1 == i && polygon == false) {
            Bresenham bsh = Bresenham(pts[0].x, pts[0].y, pts[i].x, pts[i].y);
            bsh.drawLine();
            return;
        }
        Bresenham bsh = Bresenham(pts[i].x, pts[i].y, pts[i+1].x, pts[i+1].y);
        bsh.drawLine();
        std::cout<<"Drawing polygon"<<std::endl;
    }
}

void Polygon::addPoint(Pixel x) {
    if (!pts.empty()) {
        if (x.x == pts.front().x && x.y == pts.front().y) {
            std::cout<<"Done"<<std::endl;
        }
    }
//    std::cout<<"Polygon added point"<<std::endl;
    pts.push_back(x);
}

void Polygon::clear() {
    pts.clear();
}
