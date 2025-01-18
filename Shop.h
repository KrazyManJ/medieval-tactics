#ifndef SHOP_H
#define SHOP_H
#include "UnitFactory.h"
#include "Player.h"

class Shop {
private:
    bool isFirstPlayerReady;
    bool isSecondPlayerReady;
    std::string selectedBuyingUnit;
public:
    Shop();
    void buyUnitForCurrentPlayer(std::string unitID, int row, int column);
    void selectBuyingUnit(std::string unitName);
    bool isReady();
    void markReady();
    ~Shop();
};

#endif // SHOP_H
