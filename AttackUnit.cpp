#include "AttackUnit.h"
#include "vector"

AttackUnit::AttackUnit(float hp, int defense, int walkingRange, int abilityRange, int cost,
                     const std::vector<GroundType>& enterableGroundType, const Position& position,
                     float buildPower, const std::string& name, const std::string& description)
    : Unit(hp, defense, walkingRange, abilityRange, cost, enterableGroundType, position, buildPower, name, description)
{
}

float AttackUnit::getAttackPower()
{
    return m_power;
}

void AttackUnit::useAbility(int row, int column)
{
    auto* game = Game::getInstance();
    auto* enemyPlayer = game->getOponentPlayerOfPlayerOnTurn();
    std::vector<Unit*> enemyUnits = enemyPlayer->getUnits();
    for(Unit* enemyUnit : enemyUnits){
        if(enemyUnit->getPosition().row == row
            and enemyUnit->getPosition().column == column){
            enemyUnit->setHp(enemyUnit->getHp()-(getAttackPower()/enemyUnit->getDefense()));
        };
    };
}
