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


inline int WIDTH = 800, HEIGHT = 600;

typedef struct RGBColor {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RGBColor;

#include <GLUT/GLUT.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>
#include <algorithm>
#include <array>
#include <unistd.h>


#include "Pixel.cpp"
#include "Line.hpp"
#include "DDA.hpp"
#include "Rectangle.hpp"
#include "Bresenham.hpp"
#include "MidPoint.hpp"
#include "Ellipse.hpp"
#include "Parabola.hpp"
#include "Hyperbola.hpp"
#include "Polygon.hpp"

#include "Menu.hpp"
#include "Mouse.hpp"
#include "Keyboard.hpp"

//MARK:- WINDOW
static int window; 
static int menuFlag = 0;

inline Pixel currentPxl = Pixel(-1,-1);
inline std::vector<Pixel> pts;
inline bool stopDraw;
inline bool isDrawing = false;

inline bool rectangle = false;
inline bool circle = false;
inline bool ellipse = false;
inline bool polygon = false;

inline std::vector<Ellipse> ellipseCollector;
inline std::vector<MidPoint> circleCollector;
inline std::vector<Rectangle> rectangleCollector;
inline std::vector<Polygon> polygonCollector;
inline std::vector<std::tuple<Pixel,RGBColor>> color;

inline std::vector<Pixel> poly;

inline bool red = false;
inline bool green = false;
inline bool blue = false;
inline bool coloring = false;
inline bool transformation = false;

enum KeyboardButton {
    Lockwise,
    CounterLockwise,
    Up,
    Down,
    Left,
    Right,
    Bigger,
    Smaller
};

enum Orientation {
    ClockWise,
    CounterClockWise,
    Colinear
};

inline KeyboardButton KEY;

void init();
std::vector< std::vector<int> > readFile();

void capture();

void calculateMSE(std::vector<Pixel>, std::vector<Pixel>);

//MARK:- Draw
void putPixel(int, int, RGBColor);
void display(void);
void drawShape(std::vector<std::vector<int>> data);
void changeSize(int w, int h);

void groundTruth(int, int, int, int);
void circleTruth(int, int ,int);
void ellipseTruth(int x,int y,float StAngle,float EndAngle,int RX, int RY);
void parabolaTruth();

void createMenu();

// MARK: Coloring
bool isTheSameColor(RGBColor, RGBColor);
RGBColor getPixel(int x, int y);
void BoundaryFill(int x, int y, RGBColor fColor, RGBColor bColor);

// MARK: check points inside
bool onSegment(Pixel, Pixel, Pixel);
Orientation orientation(Pixel, Pixel, Pixel);
bool dotIntersect(Pixel, Pixel, Pixel);
bool isInside(Polygon, Pixel);
#endif /* Header_h */

