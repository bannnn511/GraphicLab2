//
//  Menu.cpp
//  Lab-01
//
//  Created by An on 4/27/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#include "Menu.hpp"


void processMainMenu(int option) {
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
