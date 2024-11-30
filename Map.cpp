//
// Created by MiloslavŠvábenský(ml on 30.11.2024.
//

#include "Map.h"

Map::Map(){
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            mapMatrix.at(r).at(c) = new MapObject(true, GroundType::Grass);
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
    if (row < 0 || row > rows || column < 0 || column > columns) {
        return nullptr;
    }
    return mapMatrix.at(row).at(column);
}

Map::~Map() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            delete mapMatrix.at(r).at(c);
        }
    }
}
