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

void AttackUnit::ability(int row, int column)
{
    auto* game = Game::getInstance();
    auto* enemyPlayer = game->getOponentPlayerOfPlayerOnTurn();
    std::vector<Unit*> enemyUnits = enemyPlayer->getUnits();

    for(Unit* enemyUnit : enemyUnits){
        if(enemyUnit->getPosition().row == row && enemyUnit->getPosition().column == column) {
            enemyUnit->setHp(enemyUnit->getHp()-(getAttackPower()/enemyUnit->getDefense()));
            break;
        }
    };
}

bool AttackUnit::abilityAppliable(int row, int col) {
    std::vector<Unit*> enemyUnits = Game::getInstance()->getOponentPlayerOfPlayerOnTurn()->getUnits();
    return std::any_of(
        enemyUnits.begin(),
        enemyUnits.end(),
        [row,col](Unit* u){ return u->getPosition().row == row && u->getPosition().column == col && !u->isDead(); }
        );
}

std::string AttackUnit::abilityName() {
    return "Attack";
}
