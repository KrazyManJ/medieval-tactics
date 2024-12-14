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

void BuildUnit::useAbility(int row, int column)
{
    auto* game = Game::getInstance();
    auto* map = game->getMap();
    auto* mapObject = map->getObjectAt(row, column);
    mapObject->setIsSolid(true);
    mapObject->setType(GroundType::Tree);

}
