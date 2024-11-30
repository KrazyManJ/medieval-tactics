//
// Created by MiloslavŠvábenský(ml on 30.11.2024.
//

#include "Map.h"

Map::Map(){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            mapMatrix[i][j] = new MapObject(true, Grass);
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
    return mapMatrix[row][column];
}

Map::~Map() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            delete mapMatrix[i][j];
        }
    }
}