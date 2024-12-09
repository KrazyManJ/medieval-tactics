//
// Created by MiloslavŠvábenský(ml on 30.11.2024.
//

#ifndef MAP_H
#define MAP_H
#include "IQMLSerializable.h"
#include "MapObject.h"
#include <array>



class Map:public IQMLSerializable {
    static constexpr int rows = 5;
    static constexpr int columns = 5;
    std::array<std::array<MapObject*, columns>, rows> mapMatrix;

public:
       Map();
       int getWidth();
       int getHeight();
       // TODO: Implement Map::isInRange(int row, int column);
       MapObject* getObjectAt(int row, int column);
       QVariantMap serialize();
       ~Map();
};



#endif //MAP_H
