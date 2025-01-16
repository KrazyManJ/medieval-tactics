#ifndef SHOP_H
#define SHOP_H
#include "UnitFactory.h"
#include "Player.h"

class Shop {
private:
    bool isFirstPlayerReady;
    bool isSecondPlayerReady;
public:
    Shop();
    void buyUnitForCurrentPlayer(std::string unitID, int row, int column);
    bool isReady();
    void markReady();
    ~Shop();
};

#endif // SHOP_H
