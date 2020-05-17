//
//  Polygon.hpp
//  Lab-01
//
//  Created by An on 5/2/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef Polygon_hpp
#define Polygon_hpp

#include <vector>
#include "../Pixel.cpp"

class Polygon {
private:
    std::vector<Pixel> pts;
    int angle = 1;
public:
    void drawPolygon();
    void addPoint(Pixel x);
    void clear();
    
    Pixel getPointByIndex(int);
    Polygon transformation();
    
    void translation(int);
    void scaling(int);
    void rotation(int);
    int size();
};

#endif /* Polygon_hpp */
