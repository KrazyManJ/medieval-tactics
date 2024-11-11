//
// Created by Ivo Pisařovic on 24/09/2020.
//

#include "Tesla.h"
#include <cstdlib>

Tesla::Tesla(const int x, const int y) {
    this->x = x;
    this->y = y;
    this->energy = ENERGY_DEFAULT;
}

int Tesla::getX() const {
    return x;
}

int Tesla::getY() const {
    return y;
}

int Tesla::getEnergy() const {
    return energy;
}

void Tesla::moveTo(const int x, const int y) {
    this->x = x;
    this->y = y;
    this->energy -= abs(x)+abs(y);
}

void Tesla::charge() {
    this->energy++;
}
