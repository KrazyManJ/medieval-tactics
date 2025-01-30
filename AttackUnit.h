#ifndef ATTACKUNIT_H
#define ATTACKUNIT_H

#include "Unit.h"
#include "Game.h"

class AttackUnit : public Unit
{
public:
    AttackUnit(float hp, int defense, int walkingRange, int abilityRange, int cost,
              const std::vector<GroundType>& enterableGroundType, const Position& position,
              float buildPower, const std::string& name, const std::string& description);
    float getAttackPower();

    void ability(int row, int column) override;
    bool abilityAppliable(int row, int col) override;
    std::string abilityName() override;
};

#endif // ATTACKUNIT_H
