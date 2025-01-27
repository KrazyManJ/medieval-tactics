#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "IQMLSerializable.h"
#include "Unit.h"

class Player : public IQMLSerializable
{
private:
    std::vector<Unit*> units;
    std::vector<Unit*>::iterator selectedUnit;
    std::string color;
    int money;
public:
    Player(std::string color, int money);

    std::vector<Unit*> getUnits() const;
    Unit* getSelectedUnit() const;
    std::string getColor() const;
    int getMoney() const;

    bool hasSelectedUnit() const;
    void addUnit(Unit* unit);
    void selectUnit(int row, int column);

    void deselectUnit();

    void useSelectedUnit(int row, int column);
    void moveSelectedUnit(int row, int column);
    int getNumberOfUnits();

    QVariantMap serialize() override;

    ~Player();
};

#endif // PLAYER_H
