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
public:
    void drawPolygon();
    void addPoint(Pixel x);
};

#endif /* Polygon_hpp */
