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

typedef struct
{
    u_char head[12];
    u_short dx /* Width */, dy /* Height */, head2;
    u_char pic[768 * 1024 * 10][3];
} typetga;

typetga tga;

char captureName[256];
u_long captureNo;
u_char tgahead[12] = {0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

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
    
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        drawShape(data);
//        capture(window);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
        
//        std::this_thread::sleep_for(std::chrono::seconds(60));
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

void capture(GLFWwindow* window)
{
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight); /* Get size, store into specified variables  */
    
    /* Prepare the targa header */
    memcpy(tga.head, tgahead, 12);
    tga.dx = screenWidth;
    tga.dy = screenHeight;
    tga.head2 = 0x2018;
    
    /* Store pixels into tga.pic */
    
    glReadPixels(0, 0, screenWidth, screenHeight, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, tga.pic[0]);
//    std::cout<<tga.pic[0]<<std::endl;
    for (int i= 0; i< (768 * 1024 );i++) {
        if(tga.pic[i][0] != 0 || tga.pic[i][1] != 0 || tga.pic[i][2] != 0) {
            std::cout<<"Index: "<<i<<std::endl;
            int x = tga.pic[i][0];
            int y = tga.pic[i][1];
            int z = tga.pic[i][2];
            std::cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<std::endl;
        }
    }
    /* Store "Capture_%04lu.tga" + captureNo into captureName, increase frame count */
//    sprintf(captureName, "Capture_%04lu.tga" /* 'lu' for unsigned long */, captureNo); captureNo++;
//
//    /* Write file */
//    FILE* cc = fopen(captureName, "wb");
//    fwrite(&tga, 1, (18 + 3 * screenWidth * screenHeight), cc);
//    fclose(cc);
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
