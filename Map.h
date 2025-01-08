#ifndef MAP_H
#define MAP_H
#include "IQMLSerializable.h"
#include "MapObject.h"
#include <array>



class Map:public IQMLSerializable {
    static constexpr int rows = 6;
    static constexpr int columns = 12;
    std::array<std::array<MapObject*, columns>, rows> mapMatrix;

public:
       Map();
       int getWidth();
       int getHeight();
       bool isInRange(int row, int column);
       MapObject* getObjectAt(int row, int column);
       QVariantMap serialize();
       ~Map();
};



#endif //MAP_H
