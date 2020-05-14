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

Polygon Polygon::transformation() {
    if (KEY == Left || KEY == Right || KEY == Up || KEY == Down) {
        translation(KEY);
    }
    if (KEY == Bigger || KEY == Smaller) {
        scaling(KEY);
    }
    
    if (KEY == Lockwise || KEY == CounterLockwise) {
        rotation(KEY);
    }
   
    return Polygon();
}

void Polygon::translation(int key) {
    for(int i =0; i<= pts.size()-1; i++) {
        switch (key) {
            case Left:
                pts[i].x--;
                break;
            case Right:
                pts[i].x++;
                break;
            case Up:
                pts[i].y++;
                break;
            case Down:
                pts[i].y--;
                break;
            default:
                break;
        }
    }
}

void Polygon::scaling(int key) {
    double increment = 1;
    switch (key) {
        case Bigger: {
            increment = 1.1;
            break;
        }
        case Smaller: {
            increment = 0.90909091;
            break;
        }
        default:
            break;
    }
    for(int i =0; i<= pts.size()-1; i++) {
        pts[i].x *= increment;
        pts[i].y *= increment;
    }
}

void Polygon::rotation(int key) {
    double c = cos(angle *3.14/180);
    double s = sin(angle *3.14/180);
    
    for(int i =0; i <= pts.size()-1; i++) {
        double xOld = pts[i].x;
        double yOld = pts[i].y;
        
        switch (key) {
            case Lockwise:
                pts[i].x = xOld*c + yOld*s;
                pts[i].y = -xOld*s + yOld*c;
                break;
                
            case CounterLockwise:
                pts[i].x = xOld*c - yOld*s;
                pts[i].y = +xOld*s + yOld*c;
                break;
        }
    }
    angle++;
}
