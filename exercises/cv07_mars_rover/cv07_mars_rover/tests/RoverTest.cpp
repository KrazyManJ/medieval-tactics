#include "RoverTest.hpp"

#include "Rover.h"
#include "Ice.h"
#include "Water.h"
#include "Soil.h"
#include "Concrete.h"


void RoverTest::run() {
    testProcessMaterialInStorageWithIce();
    testProcessMaterialInStorageWithSoil();
}

void RoverTest::testProcessMaterialInStorageWithIce() {
    Rover<Ice, Water>rover;
    auto ice = std::make_unique<Ice>();
    rover.add(ice);
    test_(ice == nullptr);
    std::vector<Water> waterVec = rover.process();
    test_(waterVec.size() == 1);
    test_(rover.process().size() == 0);
    
}

void RoverTest::testProcessMaterialInStorageWithSoil() {
    Rover<Soil, Concrete>rover;
    auto soil = std::make_unique<Soil>();
    rover.add(soil);
    test_(soil == nullptr);
    std::vector<Concrete> waterVec = rover.process();
    test_(waterVec.size() == 1);
    test_(rover.process().size() == 0);
}
