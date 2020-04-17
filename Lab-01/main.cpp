//
//  main.cpp
//  Lab-01
//
//  Created by An on 4/16/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//


#define GLEW_STATIC

#include "Header.h"

const GLint WIDTH = 800, HEIGHT = 500;



int main(int argc, const char * argv[]) {
    if (!glfwInit()) {
        glfwTerminate();
        return -1;
    }
    
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Lab 01", nullptr, nullptr);
    
    if(!window) {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,WIDTH,0.0,HEIGHT,0.0,100.0);
    
    if(glewInit() != GLEW_OK) {
        glfwTerminate();
        return -1;
    }
    
    DDA dda;
    Bresenham bsh;
    
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
//        glClearColor(1, 1, 1, 1);
        dda.drawLine(0, 0, 90, 200);
        bsh.drawLine(0, 0, 90, 200);
//        bsh.drawLine2(0, 0, 90, 200);
        groundTruth(0, 0, 90, 200);
        
        dda.drawLine(60, 60, 450, 160);
        bsh.drawLine(60, 60, 450, 160);
//        bsh.drawLine2(0, 0, 450, 160);
        groundTruth(60, 60, 450, 160);
     
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}

void groundTruth(int x1, int y1, int x2, int y2) {
    glBegin(GL_LINES);
    glColor3f(0, 0, 1);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}
