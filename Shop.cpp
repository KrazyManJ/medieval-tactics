#include "Shop.h"

Shop::Shop() {
    isFirstPlayerReady = false;
    isSecondPlayerReady = false;
}

void Shop::buyUnitForCurrentPlayer(int row, int column) {
    Game* game = Game::getInstance();



    Unit* unit = UnitFactory::createUnit(selectedBuyingUnit, row, column);
    if(isFirstPlayerReady == false) {
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
    if(isFirstPlayerReady == true && isSecondPlayerReady == true) {
        return true;
    } else {
        return false;
    }
}

void Shop::markReady() {
    if(isFirstPlayerReady == false) {
        isFirstPlayerReady = true;
    } else {
        isSecondPlayerReady = true;
    }
}

