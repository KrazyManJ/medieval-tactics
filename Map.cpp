#include "Map.h"

#include <map>

Map::Map(){
    const std::string mapString =
        "HHHGGGGGSWWWWWSGGGGGGGTTTT\n"
        "HHHGGGGGSWWWWWSSGGGGGGGGTT\n"
        "HHGGGGGGGGGGGGGGGGGHGGGGGT\n"
        "HGGGGGGGGGGGGGGGGGGHGGGGGG\n"
        "GGGGGGGGGGMWWWWWSGGGGGGGGG\n"
        "GGGGGGGGGMMWWWWWSGGGGGGGGG\n"
        "GGGGGGHGGGMMWWWWWSGGGGGGGH\n"
        "GGGGGGHGGGGMMWWWWSGGGGGGHH\n"
        "GGGGGGGGGGGGMWWWWSGGGGGGGG\n"
        "TTTTGGGGGGGGGGGGGGGGGGGGGG\n"
        "TTTTTGGGGGGGGGGGGGGGGGGGGH\n"
        "TTTTTGGGGGGGSWWWWWSGGGGGHH\n"
        ;

    std::map<char, std::function<MapObject*()>> charMappings = {
        {'G',[](){ return new MapObject(false, GroundType::Grass); } },
        {'W',[](){ return new MapObject(false, GroundType::Water); } },
        {'S',[](){ return new MapObject(false, GroundType::Sand); } },
        {'M',[](){ return new MapObject(false, GroundType::Mud); } },
        {'H',[](){ return new MapObject(true, GroundType::Hill); } },
        {'T',[](){ return new MapObject(true, GroundType::Tree); } },
    };

    unsigned short row = 0, col = 0;
    for (char c : mapString) {
        if (c == '\n') {
            row++;
            col = 0;
            continue;
        }
        mapMatrix.at(row).at(col) = charMappings.at(c)();
        col++;
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
