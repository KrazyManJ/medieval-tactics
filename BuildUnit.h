#ifndef BUILDUNIT_H
#define BUILDUNIT_H

#include "Unit.h"
#include "Game.h"

class BuildUnit : public Unit
{
public:
    BuildUnit(float hp, int defense, int walkingRange, int abilityRange, int cost,
              const std::vector<GroundType>& enterableGroundType, const Position& position,
              float buildPower, const std::string& name, const std::string& description);
    float getBuildPower();

    void ability(int row, int column) override;
    bool abilityAppliable(int row, int col) override;
    std::string abilityName() override;
};

#endif // BUILDUNIT_H
