#ifndef UNIT_H
#define UNIT_H
#include <Position.h>
#include <GroundType.h>
#include "vector"
#include "iostream"


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
    float getHp();
    void setHp(float hp);
    int getDefense();
    void move(int row, int column);
    virtual void useAbility()= 0;
    virtual std::string getAbilityName()=0;
    bool isInWalkingRange(int row, int column);
    bool isInAbilityRange(int row, int column);
    std::vector<GroundType> getEnterableGroundType();
    ~Unit();

};


#endif // UNIT_H
