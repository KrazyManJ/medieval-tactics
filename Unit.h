#ifndef UNIT_H
#define UNIT_H
#include <Position.h>
#include <GroundType.h>
#include "vector"
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

    virtual void ability(int row, int col) = 0;
    virtual bool abilityAppliable(int row, int col) = 0;

    float getHp();
    void setHp(float hp);
    int getDefense();
    int getCost();
    std::string getName();
    std::string getDescription();
    void move(int row, int column);
    bool isInWalkingRange(int row, int column);
    bool canUseAbilityAt(int row, int column);
    std::vector<GroundType> getEnterableGroundType();
    void useAbility(int row, int column);
    QVariantMap serialize() override;
    Position getPosition();
    int getWalkingRange();

};


#endif // UNIT_H
