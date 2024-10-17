#ifndef MAZE_H
#define MAZE_H


#include <array>
#include <vector>
#include "Tesla.h"
#include "Position.h"

class Map {
private:
    Tesla* tesla;
    std::array<std::array<char, 5>, 5> plan;
    std::vector<Position> charges;
public:
    Map();
    Map(int startX, int startY);
    void print() const;
    bool checkMoveAvailability(const int x, const int y) const;
    void moveTesla(const int x, const int y);
    Tesla* getTesla();
};


#endif //UNTITLED_MAZE_H
