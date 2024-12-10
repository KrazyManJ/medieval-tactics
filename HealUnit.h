#ifndef HEALUNIT_H
#define HEALUNIT_H

#include "Unit.h"
#include "Game.h"

class HealUnit : public Unit
{
public:
    HealUnit(float hp, int defense, int walkingRange, int abilityRange, int cost,
               const std::vector<GroundType>& enterableGroundType, const Position& position,
               float buildPower, const std::string& name, const std::string& description);
    float getHealPower();
    void useAbility(int row, int column) override;
};

#endif // HEALUNIT_H
