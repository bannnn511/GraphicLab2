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
    mouse->setXorigin(x);
    mouse->setYorigin(HEIGHT-y);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (stopDraw) {
            pts.clear();
        }
        stopDraw = false;
        std::cout<<"Push cooor: "<<currentPxl.x<<" "<<currentPxl.y<<std::endl;
        pts.push_back(currentPxl);
    }
    if ( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN ) {
        std::cout<<"End point:"<<x<<"- "<<y<<std::endl;
        stopDraw = true;
    }
    glutPostRedisplay();
}

void Mouse::mouseMove(int x, int y) {
    std::cout<<"x: "<<x<<" y: "<<y<<std::endl;
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
