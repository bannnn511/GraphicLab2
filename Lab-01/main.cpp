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

//MARK:- MAIN
int main(int argc, char * argv[]) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("Lab2");
      
    init();
    glutDisplayFunc(display);

    createPopupMenu();
    glutMainLoop();
    return 0;
}

//MARK: INIT
void init() {
    glClearColor(0, 0, 0, 0);

    glViewport(0, 0, WIDTH, HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, WIDTH, 0, HEIGHT, 1, -1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPointSize(5);
}

//MARK:- DISPLAY
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    std::vector<std::vector<int>> data = readFile();
    drawShape(data);
 

    glutSwapBuffers();
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

void ellipseTruth(int x,int y,float StAngle,float EndAngle,int RX, int RY) {
    double i, inc;
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0);
    inc=3.14/fmax(RX,RY)/2;
    i=StAngle;
    while(i<=EndAngle)
    {
        glVertex2f(int((RX*cos(i)+y)+.5),int((RY*sin(i)+x)+.5));
        i=i+inc;
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

void capture(GLFWwindow* window){
    int screenWidth, screenHeight;

    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    GLfloat *p;
    p = new GLfloat[3*WIDTH * HEIGHT];
    glReadPixels(0, 0, WIDTH, HEIGHT, GL_RGB, GL_FLOAT, p);
    for (int a = 0; a < 3*WIDTH * HEIGHT-2; a = a + 3) {
        //cout << p[i] << endl;
        int i = a;
        if (p[i] == float(0) && p[i+1] == float(0) && p[i+2]== float(1)) {
            float row = i / ( 3*(screenHeight-1));
            float column = i / ( 3*(screenWidth-1));
            std::cout << row << " " << column << std::endl;
            glBegin(GL_POINTS);
            glVertex2i(row, column);
            glEnd();
        }
    }
}

//MARK:- Draw shape
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
                double time =elapsed.count()*pow(10,3);
                std::cout << "DDA line draw time: " << time <<std::endl;
                
                start = std::chrono::high_resolution_clock::now();
                groundTruth(data[i][1], data[i][2], data[i][3], data[i][4]);
                finish = std::chrono::high_resolution_clock::now();
                elapsed = finish - start;
                time = elapsed.count()*pow(10,3);
                std::cout << "OpenGL line draw time: " << time <<std::endl;
                
                break;
             }
            case 1: {
                Bresenham bsh = Bresenham(data[i][1], data[i][2], data[i][3], data[i][4]);
                auto start = std::chrono::high_resolution_clock::now();
                bsh.drawLine();
                auto finish = std::chrono::high_resolution_clock::now();
                std::chrono::duration<float> elapsed = finish - start;
                double time =elapsed.count()*pow(10,3);
                std::cout<<"Bresenham line draw time: "<<time <<std::endl;
     
                start = std::chrono::high_resolution_clock::now();
                groundTruth(data[i][1], data[i][2], data[i][3], data[i][4]);
                finish = std::chrono::high_resolution_clock::now();
                elapsed = finish - start;
                time =elapsed.count()*pow(10,3);
                std::cout << "OpenGL line draw time: " << time <<std::endl;
                
                break;
            }
            case 2: {
                MidPoint mpt= MidPoint(data[i][1], data[i][2], data[i][3]);
                auto start = std::chrono::high_resolution_clock::now();
                mpt.drawCircle();
                auto finish = std::chrono::high_resolution_clock::now();
                std::chrono::duration<float> elapsed = finish - start;
                double time =elapsed.count()*pow(10,3);
                std::cout<<"Midpoint circle draw time: "<<time <<std::endl;
                break;
            }
            case 3: {
                Ellipse ellps (data[i][1], data[i][2], data[i][3], data[i][4]);
                auto start = std::chrono::high_resolution_clock::now();
                ellps.drawEllipse();
                auto finish = std::chrono::high_resolution_clock::now();
                std::chrono::duration<float> elapsed = finish - start;
                double time =elapsed.count()*pow(10,3);
                std::cout<<"Midpoint ellipse draw time: "<<time<<std::endl;
                break;
            }
            case 4: {
                Parabola para = Parabola(data[i][1], data[i][2], data[i][3]);
                auto start = std::chrono::high_resolution_clock::now();
                para.drawParabola();
                auto finish = std::chrono::high_resolution_clock::now();
                std::chrono::duration<float> elapsed = finish - start;
                int time =elapsed.count()*pow(10,3);
                std::cout<<"Midpoint parabola draw time: "<<time <<std::endl;
                break;
            }
            default:
                break;
        }
    }
}

//MARK: MSE
void calculateMSE(std::vector<Pixel> data, std::vector<Pixel> standard) {
    int d = 0;
    int se = 0;
    for (int i=0; data.size(); i++) {
        d = (data[i].y - standard[i].y)^2;
        se += d;
    }
    float mse = se/(data.size()-1);
    std::cout<<"Sum error: "<<se<<std::endl;
    std::cout<<"Mean square err: "<<mse<<std::endl;
}
