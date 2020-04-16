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
    
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        dda.drawLine(20, 20, 140, 160);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
