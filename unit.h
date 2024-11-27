#ifndef UNIT_H
#define UNIT_H
#include <Position.h>
#include <GroundType.h>
#include "vector"


class Unit
{
    float m_hp;
    int m_defense;
    int m_walkingRange;
    int m_abilityRange;
    int m_cost;
    std::vector<GroundType> m_enterableGroundType;
    Position m_position;

public:
    Unit(float hp, int defense, int walkingRange,
         int abilityRange, int cost,
         std::vector<GroundType> enterableGroundType, Position positon);

};

#endif // UNIT_H
