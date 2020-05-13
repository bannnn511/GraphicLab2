//
//  Keyboard.cpp
//  Lab-01
//
//  Created by An on 5/11/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#include "Keyboard.hpp"

void processKeyboard(unsigned char key, int x, int y) {
    if (key == 76 || key == 108) {
        std::cout<<"L key"<<std::endl;
        KEY = Lockwise;
    }
    
    if (key == 82 || key == 114) {
        std::cout<<"R key"<<std::endl;
        KEY = CounterLockwise;
    }
    
    if (key == 43) {
        std::cout<<"+ key"<<std::endl;
        KEY = Bigger;
    }
    
    if (key == 45) {
        std::cout<<"- key"<<std::endl;
        KEY = Smaller;
    }
    transformation = true;
    clearMenu();
    glutPostRedisplay();
}

void processSpecialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            std::cout<<"Left button key"<<std::endl;
            KEY = Left;
            break;
        case GLUT_KEY_RIGHT:
            std::cout<<"Right button key"<<std::endl;
            KEY = Right;
            break;
        case GLUT_KEY_UP:
            std::cout<<"Up button key"<<std::endl;
            KEY = Up;
            break;
        case GLUT_KEY_DOWN:
            std::cout<<"Down button key"<<std::endl;
            KEY = Down;
            break;
        default:
            break;
    }
    transformation = true;
    clearMenu();
    glutPostRedisplay();
}
