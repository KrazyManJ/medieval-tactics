#include "MapTest.hpp"
#include "Map.h"

void MapTest::testMoveSuccess() {
    Map map(3,3);
    test_(map.checkMoveAvailability(1, -1)); // check
    map.moveTesla(1,-1);
    test_(map.getTesla()->getEnergy()==9); // lower energy
    test_(map.getTesla()->getX()==4); // x position check
    test_(map.getTesla()->getY()==2); // y position check
}

void MapTest::testMoveHitBoundary() {
    Map map(0,0);
    test_(!map.checkMoveAvailability(-1, 0)); //left boundary
    test_(!map.checkMoveAvailability(0, -1)); //top boundary
    for (int i = 0; i < 4; i++) map.moveTesla(1, 1);
    test_(!map.checkMoveAvailability(1, 0)); //right boundary
    test_(!map.checkMoveAvailability(0, 1)); //bottom boundary
}

void MapTest::run() {
    this->testMoveSuccess();
    this->testMoveHitBoundary();
    this->testOutOfEnergy();
}

