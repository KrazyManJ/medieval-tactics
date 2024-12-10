#include "HealUnit.h"

HealUnit::HealUnit(float hp, int defense, int walkingRange, int abilityRange, int cost,
                     const std::vector<GroundType>& enterableGroundType, const Position& position,
                     float buildPower, const std::string& name, const std::string& description)
    : Unit(hp, defense, walkingRange, abilityRange, cost, enterableGroundType, position, buildPower, name, description)
{
}

float HealUnit::getHealPower()
{
    return m_power;
}

void HealUnit::useAbility(int row, int column)
{
    auto* game = Game::getInstance();
    auto* Player = game->getPlayerOnTurn();
    std::vector<Unit*> yourUnits = Player->getUnits();

    for(Unit* yourUnit : yourUnits){

        if(yourUnit->getPosition().row == row
            and yourUnit->getPosition().column == column){
            yourUnit->setHp(yourUnit->getHp()+getHealPower());
        };

    };
}
