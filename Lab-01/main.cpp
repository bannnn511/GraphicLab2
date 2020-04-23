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
    
    std::vector<std::vector<int>> data = readFile();
    
    
//        Bresenham bsh2 = Bresenham(20, 60 ,100, 300);
    //    MidPoint mpt = MidPoint(300, 120, 70);
    //    MidPoint mpt2 = MidPoint(500, 120, 70);
    //
    //    Ellipse ecl = Ellipse(400, 300, 100, 150);
    //    Parabola para = Parabola(50, 200, 10);
    //    Hyperbola hbla = Hyperbola(200,200,80,90);
    
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        //        bsh.drawLine();
//                bsh2.drawLine();
        //        groundTruth(50, 50, 90, 10);
        //        groundTruth(20, 60 ,100, 300);
        //        mpt.drawCircle();
        //        mpt2.drawCircle();
        //        circleTruth(300, 300, 100);
        //
        //        ecl.drawEclipse();
        //        para.drawParabola();
        //        parabolaTruth();
        
        //        hbla.drawHyperbola();
        drawShape(data);
        glfwSwapBuffers(window);
        glfwPollEvents();
        std::this_thread::sleep_for(std::chrono::seconds(60));
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

void parabolaTruth() {
    glColor3f(0, 0, 0);
    glBegin(GL_POINTS);
    for (double x = 0; x <= 7; x += 0.01) {
        glVertex2f(x, (double) sqrt(4*x));
        glVertex2f(x, -(double) sqrt(4*x));
    }
}

void putPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

std::vector<std::vector<int>> readFile() {
    std::ifstream fin;
    fin.open("/Users/apple/Desktop/Stduy/Test/Computer Graphic/Lab-01/Lab-01/read.txt");
    if (!fin) {
        std::cout << "Cannot open file";
        exit(1);
    }
    
    std::string line;
    std::vector<std::vector<int> > data;
    while (getline(fin, line)) {
        std::istringstream is(line);
        data.push_back(std::vector<int>(std::istream_iterator<int>(is), std::
                                        istream_iterator<int>()));
    }
    
    fin.close();
    
    return data;
}

void drawShape(std::vector<std::vector<int>> data) {
    for (int i=0; i<data.size(); i++) {
        int jump = data[i][0];
        switch (jump){
            case 0:{
                DDA dda = DDA(data[i][1], data[i][2], data[i][3], data[i][4]);
                auto start = std::chrono::high_resolution_clock::now();
                dda.drawLine();
                auto finish = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = finish - start;
                std::cout << "DDa line draw time:" << elapsed.count() <<std::endl;
                break;
             }
            case 1: {
                Bresenham bsh = Bresenham(data[i][1], data[i][2], data[i][3], data[i][4]);
                auto start = std::chrono::high_resolution_clock::now();
                bsh.drawLine();
                auto finish = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = finish - start;
                std::cout<<"Bresenham line draw time:"<<elapsed.count() <<std::endl;
                break;
            }
            case 2: {
                MidPoint mpt= MidPoint(data[i][1], data[i][2], data[i][3]);
                auto start = std::chrono::high_resolution_clock::now();
                mpt.drawCircle();
                auto finish = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = finish - start;
                std::cout<<"Midpoint circle draw time:"<<elapsed.count() <<std::endl;
                break;
            }
            case 3: {
                Ellipse ellps (data[i][1], data[i][2], data[i][3], data[i][4]);
                auto start = std::chrono::high_resolution_clock::now();
                ellps.drawEllipse();
                auto finish = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = finish - start;
                std::cout<<"Midpoint ellipse draw time:"<<elapsed.count() <<std::endl;
                break;
            }
            case 4: {
                Parabola para = Parabola(data[i][1], data[i][2], data[i][3]);
                auto start = std::chrono::high_resolution_clock::now();
                para.drawParabola();
                auto finish = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = finish - start;
                std::cout<<"Midpoint parabola draw time:"<<elapsed.count() <<std::endl;
                break;
            }
            default:
                break;
        }
    }
}
