#include "BuildUnit.h"


BuildUnit::BuildUnit(float hp, int defense, int walkingRange, int abilityRange, int cost,
                     const std::vector<GroundType>& enterableGroundType, const Position& position,
                     float buildPower, const std::string& name, const std::string& description)
    : Unit(hp, defense, walkingRange, abilityRange, cost, enterableGroundType, position, buildPower, name, description)
{
}

float BuildUnit::getBuildPower()
{
    return m_power;
}

void BuildUnit::ability(int row, int column)
{
    auto* mapObject = Game::getInstance()->getMap()->getObjectAt(row,column);
    mapObject->setType(GroundType::Tree);
    mapObject->setIsSolid(true);
}

bool BuildUnit::abilityAppliable(int row, int col) {
    auto* mapObject = Game::getInstance()->getMap()->getObjectAt(row,col);
    return !mapObject->isSolid();
}
