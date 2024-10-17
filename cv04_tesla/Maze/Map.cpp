#include "Map.h"
#include <iostream>

Map::Map(int startX, int startY) {
    tesla = new Tesla(startX, startY);
    plan = std::array<std::array<char, 5>, 5>();
    charges = {
        Position{.x = 1, .y = 1},
        Position{.x = 2, .y = 4}
    };
    
    
    for (auto &row: plan) {
        for (auto &column: row) {
            column = '-';
        }
    }
    for (auto charge : charges) {
        plan.at(charge.x).at(charge.y) = '+';
    }
}

Map::Map() : Map(3, 3) {}

void Map::print() const {
    for (int y = 0; y < plan.size(); y++) {
        for (int x = 0; x < plan.at(y).size(); x++) {
            if (tesla->getX() == x and tesla->getY() == y) {
                std::cout << Tesla::symbol;
            }
            else {
                std::cout << plan.at(x).at(y);
            }
        }
        std::cout << std::endl;
    }
}

void Map::moveTesla(const int x, const int y) {
    tesla->moveTo(tesla->getX() + x, tesla->getY() + y);
    char &tile = plan.at(tesla->getX()).at(tesla->getY());
    if (tile == '+') {
        tile = '-';
        tesla->charge();
    }
}

bool Map::checkMoveAvailability(const int dx, const int dy) const {
    int newX = tesla->getX() + dx;
    int newY = tesla->getY() + dy;

    return (
        newX >= 0 and
        newX < plan.at(0).size() and
        newY >= 0 and
        newY < plan.size() and
        tesla->getEnergy() > 0
    );
}

Tesla* Map::getTesla() {
    return tesla;
}
