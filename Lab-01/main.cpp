//
//  main.cpp
//  Lab-01
//
//  Created by An on 4/16/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//


#include "Header.h"

//MARK:- MAIN
int main(int argc, char * argv[]) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Lab2");
    
    init();
    glutDisplayFunc(display);
    
    Mouse *mouse = mouse->getInstance();
    glutMouseFunc(mouse->mouseButton);
    glutMotionFunc(mouse->mouseMove);
    
    createPopupMenu();
    
    glutKeyboardFunc(processKeyboard);
    glutSpecialFunc(processSpecialKeys);
    
    glutDisplayFunc(display);
    glutReshapeFunc(changeSize);
    
    glutMainLoop();
    
    return 0;
}

//MARK: INIT
void init() {
    
    glClearColor(0, 0, 0, 0);
    
    glViewport(0,0, WIDTH, HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, WIDTH, 0, HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//    glPointSize(5);

}

void changeSize(int w, int h) {

    float ratio;
   // Prevent a divide by zero, when window is too short
   // (you cant make a window of zero width).
    ratio = 1.0f * w / h;
   // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

   // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    gluOrtho2D(0, w, 0, h);
   // Set the clipping volume
//   gluPerspective(45,ratio,0.1,1000);
    glMatrixMode(GL_MODELVIEW);
    WIDTH = w;
    HEIGHT = h;
}

//MARK:- DISPLAY
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    //    std::vector<std::vector<int>> data = readFile();
    //    drawShape(data);
    
    Mouse *mouse = mouse->getInstance();
    double x1 = mouse->getXorigin();
    double y1 = mouse->getYorigin();
    double x2 = currentPxl.x;
    double y2 = currentPxl.y;
    
    if (rectangle == true) {
//        std::cout<<"Currently drawing rectangle"<<std::endl;
        Rectangle rect = Rectangle(x1, y1, x2, y2);
        rect.drawRectangle();
        
        if(stopDraw == true) {
            rectangleCollector.push_back(rect);
            std::cout<<"x: "<<x1<<" - "<<x2<<" y: "<<y1<<" - "<<y2<<std::endl;
            stopDraw = false;
        }
    }
    
    if (circle == true) {
//        std::cout<<"Currently drawing circle"<<std::endl;
        double r = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
        MidPoint circle = MidPoint(x1, y1, r);
        circle.drawCircle();
        
        if (stopDraw == true) {
            circleCollector.push_back(circle);
        }
    }
    
    if (ellipse == true) {
        int rA = abs(x2-x1);
        int rB = abs(y2-y1);
        
        Ellipse ellipse = Ellipse(x1, y1, rA, rB);
        ellipse.drawEllipse();
        
        if(stopDraw == true) {
            ellipseCollector.push_back(ellipse);
        }
    }
    
    if (polygon == true) {
        glBegin(GL_LINE_STRIP);
        for(int i =0; i < poly.size();i++) {
            glVertex2i(poly[i].x, poly[i].y);
        }
        glEnd();
    }
    
    if (polygon == false && !poly.empty()) {
          Polygon newPoly = Polygon();
        for (auto pt: poly) {
            newPoly.addPoint(pt);
        }
        polygonCollector.push_back(newPoly);
        poly.clear();
    }
    
    if (!rectangleCollector.empty()) {
        for (int i=0; i<=rectangleCollector.size()-1;i++) {
            if (transformation == true) {
                rectangleCollector[i] = rectangleCollector[i].transformation();
//                transformation = false;
            }
            rectangleCollector[i].drawRectangle();
        }
    }
    if (!ellipseCollector.empty() ) {
        for (auto pt: ellipseCollector) {
            pt.drawEllipse();
        }
    }
    
    if (!circleCollector.empty()) {
        for ( auto pt:circleCollector) {
            pt.drawCircle();
        }
    }
    
    if(!polygonCollector.empty()) {
        for (int i=0; i <= polygonCollector.size() -1; i++) {
            if (isInside(polygonCollector[i], Pixel(currentPxl.x, currentPxl.y))) {
                if (transformation == true) {
                    polygonCollector[i].transformation();
                    transformation = false;
                }
            }
            polygonCollector[i].drawPolygon();
        }
    }
    
    
    if(!color.empty()) {
        for (auto clr:color) {
            int x = std::get<0>(clr).x;
            int y = std::get<0>(clr).y;
            RGBColor fcolor = std::get<1>(clr);
            putPixel(x, y, fcolor);
        }
    }
    
    if (red||green||blue) {
        mouse->fillColor(currentPxl.x, currentPxl.y);
    }
    
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

//MARK: PUT PIXEL
void putPixel(int x, int y, RGBColor color) {
    unsigned char *ptr = new unsigned char [3];
    ptr[0] = color.r;
    ptr[1] = color.g;
    ptr[2] = color.b;
    
    glDrawBuffer(GL_FRONT);
    glRasterPos2i(x, y);
    glDrawPixels(1, 1, GL_RGBA, GL_UNSIGNED_BYTE, ptr);
    delete[] ptr;
    

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

void capture(){
    GLfloat *p;
    p = new GLfloat[3*WIDTH * HEIGHT];
    glReadPixels(0, 0, WIDTH, HEIGHT, GL_RGB, GL_FLOAT, p);
    std::cout<<p<<std::endl;
    for (int a = 0; a < 3*WIDTH * HEIGHT-2; a = a + 3) {
        //cout << p[i] << endl;
        int i = a;
        if (p[i] == float(1) && p[i+1] == float(0) && p[i+2]== float(0)) {
            float row = i / ( 3*WIDTH);
            float column = i % ( 3*WIDTH);
            std::cout << row << " " << column << std::endl;
            glColor3f(0, 0, 0);
            glBegin(GL_POINTS);
            glVertex2i(row, column);
            glEnd();
        }
    }
    delete [] p;
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


//MARK:- COLORING
bool isTheSameColor(RGBColor current, RGBColor now) {
    if (current.b == now.b && current.g == now.g && current.r == now.r) {
        return true;
    }
    return false;
}

RGBColor getPixel(int x, int y) {
    unsigned char * ptr = new unsigned char [3];
//    glReadBuffer(GL_FRONT);
    glReadPixels(x, y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, ptr);

    RGBColor color;
    color.r = ptr[0];
    color.g = ptr[1];
    color.b = ptr[2];
    
    delete[] ptr;
    return color;
}

void BoundaryFill(int x, int y, RGBColor fColor, RGBColor bColor) {
    RGBColor currentColor;
    
    currentColor = getPixel(x, y);
    bool checkFcolor = isTheSameColor(currentColor, fColor);
    bool checkBcolor = isTheSameColor(currentColor, bColor);
    
    if ( !checkFcolor && !checkBcolor) {
        putPixel(x, y, fColor);
        color.push_back(std::make_tuple(Pixel(x, y),fColor));
        std::cout<<"Coloring...at x: "<<x<<" y: "<<y<<std::endl;
        BoundaryFill(x+1, y, fColor, bColor);
        BoundaryFill(x, y+1, fColor, bColor);
        BoundaryFill(x-1, y, fColor, bColor);
        BoundaryFill(x, y-1, fColor, bColor);
    }
//    glutSwapBuffers();
}

// MARK:- CHECK POINT INSIDE

bool onSegment(Pixel p1, Pixel p2, Pixel p3) {
    if (p1.x <= std::max(p2.x, p3.x) && p1.x >= std::min(p2.x, p3.x) && p1.y <= std::max(p2.y, p3.y) && p1.y >= std::min(p2.y, p3.y))
        return true;
    return false;
}

Orientation orientation(Pixel p1, Pixel p2, Pixel p3) {
    int val = (p3.x-p2.x)*(p2.y-p1.y) - (p2.x-p1.x)*(p3.y-p2.y);
    if (val == 0 ) {
        return Orientation::Colinear;
    }
    return val > 1 ? Orientation::ClockWise : Orientation::CounterClockWise;
    
}

bool dotIntersect(Pixel p1, Pixel p2, Pixel p3, Pixel p4) {
    Orientation o1 = orientation(p1, p2, p3);
    Orientation o2 = orientation(p1, p2, p4);
    Orientation o3 = orientation(p3, p4, p1);
    Orientation o4 = orientation(p3, p4, p2);
    
    if (o1 != o2 && o3 != o4)
        return true;
    
    if (o1 == Orientation::Colinear && onSegment(p3, p2, p1)) return true;
    if (o2 == Orientation::Colinear && onSegment(p4, p2, p1)) return true;
    if (o3 == Orientation::Colinear && onSegment(p1, p3, p4)) return true;
    if (o4 == Orientation::Colinear && onSegment(p2, p3, p4)) return true;
    
    return false;
}

bool isInside(Polygon poly, Pixel p) {
    if (poly.size() < 3) return false;
    
    Pixel infinity = Pixel(WIDTH, p.y);
    
    int count = 0;
    for (int i = 0; i < poly.size()-1; i++) {
        int next = i +1;
        if (next <= poly.size()) {
            if (dotIntersect(poly.getPointByIndex(i), poly.getPointByIndex(next), infinity, p)){
                
                if (orientation(p,infinity,poly.getPointByIndex(i)) == Orientation::Colinear) {
                    return onSegment(poly.getPointByIndex(i), p, infinity);
                }
                count++;
            }
        }
    }
    
    if (count % 2 == 1) {
        std::cout<<"Point inside polygon"<<std::endl;
        return true;
    }
    std::cout<<"Point outside polygon"<<std::endl;
    return false;
}
