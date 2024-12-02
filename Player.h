#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Unit.h"

class Player
{
private:
    std::vector<Unit*> units;
    std::vector<Unit*>::iterator selectedUnit;
    std::string color;
    int money;
public:
    Player(std::string color, int money);

    void addUnit(Unit* unit);

    void useSelectedUnit(int row, int column);
    void moveSelectedUnit(int row, int column);

    bool hasSelectedUnit() const;
    std::vector<Unit*>::iterator getSelectedUnit() const;
    std::string getColor() const;
    int getMoney() const;

    ~Player();
};

#endif // PLAYER_H
