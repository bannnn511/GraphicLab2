//
//  Menu.cpp
//  Lab-01
//
//  Created by An on 4/27/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#include "Menu.hpp"


void processMainMenu(int option) {
    switch (option) {
    case 0:
            clearMenu();
            std::cout<<"Circle"<<std::endl;
            circle = true;
            break;
    case 1:
            clearMenu();
            std::cout<<"Ellipse"<<std::endl;
            ellipse = true;
            break;
    case 2:
            clearMenu();
            std::cout<<"Rectangle"<<std::endl;
            rectangle= true;
            break;
    case 3:
            clearMenu();
            std::cout<<"Polygon"<<std::endl;
            polygon = true;
            break;
    }
}

void createPopupMenu() {
    int menu;
    menu = glutCreateMenu(processMainMenu);
    glutAddMenuEntry("Circle",0);
    glutAddMenuEntry("Ellipse",1);
    glutAddMenuEntry("Rectangle",2);
    glutAddMenuEntry("Polygon",3);
    
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
}
