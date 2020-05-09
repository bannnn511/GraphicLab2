//
//  Menu.cpp
//  Lab-01
//
//  Created by An on 4/27/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#include "Menu.hpp"


void processMainMenu(int option) {
    clearMenu();
    clearColorMenu();
    switch (option) {
        case 0:
            std::cout<<"Circle"<<std::endl;
            circle = true;
            isDrawing = true;
            break;
        case 1:
            std::cout<<"Ellipse"<<std::endl;
            ellipse = true;
            isDrawing = true;
            break;
        case 2:
            std::cout<<"Rectangle"<<std::endl;
            rectangle= true;
            isDrawing = true;
            break;
        case 3:
            std::cout<<"Polygon"<<std::endl;
            polygon = true;
            isDrawing = true;
            break;
        case 4:
            std::cout<<"Clear"<<std::endl;
            pts.clear();
            rectangleCollector.clear();
            circleCollector.clear();
            ellipseCollector.clear();
            polygonCollector.clear();
            poly.clear();
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

void processColorMenu(int option) {
    clearColorMenu();
    clearMenu();
    switch (option) {
        case 0:
            red = true;
            std::cout<<"Red"<<std::endl;
            break;
        case 1:
            green = true;
            std::cout<<"Green"<<std::endl;
            break;
        case 2:
            blue = true;
            std::cout<<"Blue"<<std::endl;
            break;
    }
}

void createPopupMenu() {
    
    int  color;
    color = glutCreateMenu(processColorMenu);
    glutAddMenuEntry("Red",0);
    glutAddMenuEntry("Green",1);
    glutAddMenuEntry("Blue",2);
    
    int menu;
    menu = glutCreateMenu(processMainMenu);
    glutAddMenuEntry("Circle",0);
    glutAddMenuEntry("Ellipse",1);
    glutAddMenuEntry("Rectangle",2);
    glutAddMenuEntry("Polygon",3);
    glutAddMenuEntry("Done",5);
    glutAddMenuEntry("Clear", 4);
    
    glutAddSubMenu("Color", color);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutMenuStatusFunc(processMenuStatus);
}

void processMenuStatus(int status, int x, int y) {

    if (status == GLUT_MENU_IN_USE)
        menuFlag = 1;
    else
        menuFlag = 0;
}

void clearMenu() {
    rectangle = false;
    circle = false;
    ellipse = false;
    polygon = false;
    isDrawing = false;
}

void clearColorMenu() {
    red = false;
    green = false;
    blue = false;
}
