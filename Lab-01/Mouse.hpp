//
//  Mouse.hpp
//  Lab-01
//
//  Created by An on 4/28/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef Mouse_hpp
#define Mouse_hpp

#include "Header.h"


class Mouse {
private:
    float deltaAngle = 0.0f;
    int xOrigin;
    int yOrigin;
    static Mouse *mouse;
    
    Mouse() {}
    void fillColor(int, int);
public:
    static Mouse *getInstance() {
        if (mouse == NULL) {
            mouse = new Mouse();
        }
        return mouse;
    }
    static void mouseButton(int, int, int, int);
    static void mouseMove(int, int);
    
    int getXorigin();
    int getYorigin();
    void setXorigin(int);
    void setYorigin(int);
    
};
#endif /* Mouse_hpp */
