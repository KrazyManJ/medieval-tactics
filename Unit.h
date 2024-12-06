#ifndef UNIT_H
#define UNIT_H
#include <Position.h>
#include <GroundType.h>
#include "vector"
#include "iostream"
#include "IQMLSerializable.h"



class Unit : public IQMLSerializable
{
    float m_hp;
    int m_defense;
    int m_walkingRange;
    int m_abilityRange;
    int m_cost;
    std::vector<GroundType> m_enterableGroundType;
    Position m_position;
    std::string m_name;
    std::string m_description;
protected:
    float m_power;

public:
    Unit(float hp, int defense, int walkingRange,
         int abilityRange, int cost,
         std::vector<GroundType> enterableGroundType, Position positon,
         float power, std::string name, std::string description);
    float getHp();
    void setHp(float hp);
    int getDefense();
    std::string getName();
    std::string getDescription();
    void move(int row, int column);
    bool isInWalkingRange(int row, int column);
    bool isInAbilityRange(int row, int column);
    std::vector<GroundType> getEnterableGroundType();
    virtual void useAbility(int row, int column)= 0;
    QVariantMap serialize();
    Position getPosition();
    ~Unit();

};


#endif // UNIT_H
