#include "Player.h"
#include <stdexcept>


Player::Player(std::string color, int money) {
    this->color = color;
    this->money = money;
    selectedUnit = units.end();
}

void Player::addUnit(Unit* unit) {
    units.push_back(unit);
    selectedUnit = units.end();
}

std::vector<Unit *>::iterator Player::getSelectedUnit() const {
    return selectedUnit;
}

bool Player::hasSelectedUnit() const {
    return selectedUnit != units.cend();
}

std::string Player::getColor() const {
    return color;
}

int Player::getMoney() const {
    return money;
}

void Player::useSelectedUnit() {
    if (!hasSelectedUnit())
        throw new std::logic_error("No unit has player selected");
    // TODO: Rework usage of ability
    (*getSelectedUnit())->useAbility();
}

void Player::moveSelectedUnit(int row, int column) {
    if (!hasSelectedUnit())
        throw new std::logic_error("No unit has player selected");
    (*getSelectedUnit())->move(row,column);
}

Player::~Player() {
    units.clear();
}
