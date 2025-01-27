#include "Shop.h"

Shop::Shop() {
    m_isFirstPlayerReady = false;
    m_isSecondPlayerReady = false;
}

void Shop::buyUnitForCurrentPlayer(int row, int column) {
    Game* game = Game::getInstance();
    Unit* unit = UnitFactory::createUnit(selectedBuyingUnit, row, column);

    if(m_isFirstPlayerReady == false) {
        Player* player = game->getFirstPlayer();
        if(player->getMoney() >= unit->getCost()) {
            int cash = player->getMoney() - unit->getCost();
            player->setMoney(cash);
            player->addUnit(unit);
            std::cout << "Player 1 cash: " << player->getMoney() << std::endl;
        }
    } else {
        Player* player = game->getSecondPlayer();
        if(player->getMoney() >= unit->getCost()) {
            int cash = player->getMoney() - unit->getCost();
            player->setMoney(cash);
            player->addUnit(unit);
            std::cout << "Player 2 cash: " << player->getMoney() << std::endl;
        }
    }
}

void Shop::selectBuyingUnit(std::string unitName){
    selectedBuyingUnit = unitName;
}


bool Shop::isReady() {
    return m_isFirstPlayerReady == true && m_isSecondPlayerReady == true;
}

void Shop::markReady() {
    if(m_isFirstPlayerReady == false) {
        m_isFirstPlayerReady = true;
    } else {
        m_isSecondPlayerReady = true;
    }
}

bool Shop::isFirstPlayerReady() {
    return m_isFirstPlayerReady;
}
