#ifndef SHOP_H
#define SHOP_H
#include "UnitFactory.h"
#include "Player.h"

class Shop {
private:
    bool m_isFirstPlayerReady;
    bool m_isSecondPlayerReady;
    std::string selectedBuyingUnit = "Knight";
public:
    Shop();
    void buyUnitForCurrentPlayer(int row, int column);
    void selectBuyingUnit(std::string unitName);
    bool isReady();
    void markReady();
    bool isFirstPlayerReady();
    int getPlayerMoney();
    ~Shop();
};

#endif // SHOP_H
