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
    if (!pts.empty()) {
        glBegin(GL_LINE_STRIP);
        for(int i =0; i < pts.size(); i++) {
            glVertex2i(pts[i].x, pts[i].y);
        }
        glVertex2i(pts[0].x, pts[0].y);
        glVertex2i(pts[pts.size()-1].x, pts[pts.size()-1].y);
        glEnd();
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
