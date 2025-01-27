#include "Player.h"
#include <AttackUnit.h>
#include <stdexcept>


Player::Player(std::string color, int money) {
    this->color = color;
    this->money = money;
    deselectUnit();
}

void Player::addUnit(Unit* unit) {
    units.push_back(unit);
    deselectUnit();
}

std::vector<Unit*> Player::getUnits() const {
    return units;
}

void Player::selectUnit(int row, int column) {
    auto unitIt = std::find_if(units.begin(), units.end(), [row,column](Unit* unit){
        Position pos = unit->getPosition();
        return pos.row == row && pos.column == column;
    });
    if (unitIt == units.end())
        throw std::out_of_range("Index out of range");
    selectedUnit = unitIt;
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

void Player::deselectUnit() {
    selectedUnit = units.end();
}

Player::~Player() {
    units.clear();
}

int Player::getNumberOfUnits() {
    std::cout << units.size() << std::endl;
}


QVariantMap Player::serialize() {
    QVariantMap map;
    map["color"] = QString::fromUtf8(getColor().c_str());
    return map;
}
