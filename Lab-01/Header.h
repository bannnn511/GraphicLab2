//
//  Header.h
//  Lab-01
//
//  Created by An on 4/16/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//
#define GL_SILENCE_DEPRECATION

#ifndef Header_h
#define Header_h

#include "glew.h"
#include "glfw3.h"

#include <GLUT/GLUT.h>
#include <OpenGL/gl3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>
#include <algorithm>

#include "Pixel.cpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "DDA.hpp"
#include "Bresenham.hpp"
#include "MidPoint.hpp"
#include "Ellipse.hpp"
#include "Parabola.hpp"
#include "Hyperbola.hpp"
#include "Menu.hpp"

//MARK:- WINDOW
static int window; 
static int menuFlag = 0;

void init();
std::vector< std::vector<int> > readFile();

void capture(GLFWwindow* window);

void calculateMSE(std::vector<Pixel>, std::vector<Pixel>);

//MARK:- Draw
void putPixel(int, int);
void display(void);
void drawShape(std::vector<std::vector<int>> data);


void groundTruth(int, int, int, int);
void circleTruth(int, int ,int);
void ellipseTruth(int x,int y,float StAngle,float EndAngle,int RX, int RY);
void parabolaTruth();

void createMenu();

#endif /* Header_h */

