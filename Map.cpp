#include "Map.h"

Map::Map(){
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            mapMatrix.at(r).at(c) = new MapObject(false, GroundType::Grass);
        }
    }
}

int Map::getWidth(){
    return columns;
}

int Map::getHeight() {
    return rows;
}

MapObject* Map::getObjectAt(int row, int column) {
    if(!isInRange(row,column)) {
        throw std::out_of_range("Unit is out of map");
    }
    return mapMatrix.at(row).at(column);
}

bool Map::isInRange(int row, int column) {
    if (row >= 0 && row < rows && column >= 0 && column < columns) {
        return true;
    } else {
        return false;
    }
}

QVariantMap Map::serialize() {
    QVariantMap map;
    map["width"] = getWidth();
    map["height"] = getHeight();
    return map;
}


Map::~Map() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            delete mapMatrix.at(r).at(c);
        }
    }
}
