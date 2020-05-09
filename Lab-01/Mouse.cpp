//
//  Mouse.cpp
//  Lab-01
//
//  Created by An on 4/28/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#include "Mouse.hpp"

Mouse *Mouse::mouse = 0;

void Mouse::mouseButton(int button, int state, int x, int y) {

    currentPxl = Pixel(x,HEIGHT-y);
    if (polygon == true) {
        mouse->setXorigin(x);
        mouse->setYorigin(y);
    }
    std::cout<<"Mouse click x:"<<x<<" y: "<<HEIGHT - y<<std::endl;    
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            if (stopDraw) {
                pts.clear();
            }
            
            mouse->setXorigin(x);
            mouse->setYorigin(HEIGHT-y);
            
            stopDraw = false;
            if (isDrawing) {
                std::cout<<"Push cooor: "<<currentPxl.x<<" "<<currentPxl.y<<std::endl;
                pts.push_back(currentPxl);
                if (polygon == true) {
                    poly.addPoint(Pixel(currentPxl.x, currentPxl.y));
                }
            }
        } else {
            if (polygon == false)
            std::cout<<"End point: "<<currentPxl.x<<" "<<currentPxl.y<<std::endl;
            stopDraw = true;
            }
    } else if ( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN ) {
        stopDraw = true;
    }
    
    glutPostRedisplay();
}

void Mouse::mouseMove(int x, int y) {
//    std::cout<<"x: "<<x<<" y: "<<y<<std::endl;
    currentPxl = Pixel(x,HEIGHT-y);
    glutPostRedisplay();
}

int Mouse::getXorigin() {
    return this->xOrigin;
}

int Mouse::getYorigin() {
    return this->yOrigin;
}

void Mouse::setXorigin(int x) {
    this->xOrigin = x;
}

void Mouse::setYorigin(int y) {
    this->yOrigin = y;
}

void Mouse::fillColor(int x, int y) {
     RGBColor color1;
    if (red == true) {
        color1.r = 200;
        color1.g = 0;
        color1.b = 0;
    } else if ( green == true) {
        color1.r = 0;
        color1.g = 200;
        color1.b = 0;
    } else {
        color1.r = 0;
        color1.g = 0;
        color1.b = 200;
    }
    
    RGBColor color2;
    color2.r = 200;
    color2.g = 0;
    color2.b = 0;
    
    for(auto pt: rectangleCollector) {
        if (pt.checkInside(x,y)) {
            BoundaryFill(x, y, color1, color2);
             clearColorMenu();
        }
    }
    
    for(auto pt: circleCollector) {
        if (pt.checkInside(x,y)) {
            BoundaryFill(x, y, color1, color2);
            clearColorMenu();
        }
    }
    
    for(auto pt: ellipseCollector){
        if (pt.checkInside(x, y)) {
            BoundaryFill(x, y, color1, color2);
            clearColorMenu();
        }
    }
   
}
