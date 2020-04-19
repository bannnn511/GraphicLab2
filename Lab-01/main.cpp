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
    glPointSize(5);
    
    if(glewInit() != GLEW_OK) {
        glfwTerminate();
        return -1;
    }
    
    DDA dda = DDA(0, 0, 20, 100);
    Bresenham bsh = Bresenham(50, 50, 90, 10);
    Bresenham bsh2 = Bresenham(20, 60 ,100, 300);
    MidPoint mpt = MidPoint(300, 300, 100);
    
    
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        bsh.drawLine();
        bsh2.drawLine();
//        groundTruth(0, 0, 20, 100);
//        mpt.drawCircle();
//        circleTruth(300, 300, 100);
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

void circleTruth(int x, int y, int radius) {
    int i;
    int lineAmount = 100;
    
    GLfloat twicePi = 2.0f * 3.14;
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i <= lineAmount;i++) {
        glVertex2f(
                   x + (radius * cos(i *  twicePi / lineAmount)),
                   y + (radius* sin(i * twicePi / lineAmount))
                   );
    }
    glEnd();
}

void putPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

