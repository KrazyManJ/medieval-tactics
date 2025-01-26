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
        player->addUnit(unit);
    } else {
        Player* player = game->getSecondPlayer();
        player->addUnit(unit);
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
