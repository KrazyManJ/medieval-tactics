//
// Created by MiloslavŠvábenský(ml on 30.11.2024.
//

#ifndef MAP_H
#define MAP_H
#include "MapObject.h"


class Map {
    const int rows = 5;
    const int columns = 5;
    MapObject mapMatrix[rows][columns];

public:
       Map();
       int getWidth();
       int getHeight();
       MapObject* getObjectAt(int row, int column);
       ~Map();
};



#endif //MAP_H