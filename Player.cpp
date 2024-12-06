#include "Player.h"
#include <AttackUnit.h>
#include <qDebug>
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

std::vector<Unit*> Player::getUnits() const {
    return units;
}

void Player::selectUnit(int index) {
    if (index > units.size())
        throw std::out_of_range("Index out of range");
    selectedUnit = units.begin();
    std::advance(selectedUnit,index);
}

Unit* Player::getSelectedUnit() const {
    return *selectedUnit;
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

void Player::useSelectedUnit(int row, int column)  {
    if (!hasSelectedUnit())
        throw new std::logic_error("No unit has player selected");
    getSelectedUnit()->useAbility(row, column);
}

void Player::moveSelectedUnit(int row, int column)  {
    if (!hasSelectedUnit())
        throw new std::logic_error("No unit has player selected");
    getSelectedUnit()->move(row,column);
}

Player::~Player() {
    units.clear();
}
