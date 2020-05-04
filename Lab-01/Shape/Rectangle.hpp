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
    int x1;
    int y1;
    int x2;
    int y2;
public:
    Rectangle(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    
    void drawRectangle();
    Pixel getCenterPoint();
    bool checkInside(int, int);
};

#endif /* Rectangle_hpp */
