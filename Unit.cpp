#include "Unit.h"
#include <cstdlib>

Unit::Unit(float hp, int defense, int walkingRange, int abilityRange, int cost, std::vector<GroundType> enterableGroundType, Position positon)
{
    m_hp = hp;
    m_defense = defense;
    m_walkingRange = walkingRange;
    m_abilityRange = abilityRange;
    m_cost = cost;
    m_enterableGroundType = enterableGroundType;
    m_position = positon;
}

float Unit::getHp()
{
    return m_hp;
}

void Unit::setHp(float hp)
{
    m_hp = hp;
}

int Unit::getDefense()
{
    return m_defense;
}

void Unit::move(int row, int column)
{
    m_position.row = row;
    m_position.column = column;
}

bool Unit::isInWalkingRange(int row, int column)
{
    bool feedback = false;
    if(abs(row - m_position.row) <= m_walkingRange and
        abs(column - m_position.column) <= m_walkingRange){
        feedback = true;
    }
    return feedback;
}

bool Unit::isInAbilityRange(int row, int column)
{
    bool feedback = false;
    if(abs(row - m_position.row) <= m_abilityRange and
        abs(column - m_position.column) <= m_abilityRange){
        feedback = true;
    }
    return feedback;
}

std::vector<GroundType> Unit::getEnterableGroundType()
{
    return m_enterableGroundType;
}
