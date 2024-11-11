//
//  worm.hpp
//  cv01_maze
//
//  Created by Jaroslav Korčák on 26.09.2024.
//

#ifndef worm_hpp
#define worm_hpp

#include <stdio.h>

class Worm {
private:
    unsigned x;
    unsigned y;
    
public:
    Worm(unsigned startX, unsigned startY) {};
    
    void move(unsigned dx, unsigned dy);
};

#endif /* worm_hpp */
