//
//  Rectangle.hpp
//  Lab-01
//
//  Created by An on 5/2/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include "../Pixel.cpp"

class Rectangle {
private:
    double x1;
    double y1;
    double x2;
    double y2;
    double angle;
public:
    Rectangle(double x1, double y1, double x2, double y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->angle = 1;
    }
    
    void drawRectangle();
    Pixel getCenterPoint();
    bool checkInside(int, int);
    
    Rectangle transformation();
    
    void translation(int);
    void scaling(int);
    void rotation(int);
};

#endif /* Rectangle_hpp */
