#include "Shop.h"

Shop::Shop() {
    isFirstPlayerReady = false;
    isSecondPlayerReady = false;
}

void Shop::buyUnitForCurrentPlayer(std::string unitID, int row, int column) {
    Game* game = Game::getInstance();



    Unit* unit = UnitFactory::createUnit(unitID, row, column);
    if(isFirstPlayerReady == false) {
        Player* player = game->getFirstPlayer();
        player->addUnit(unit);
    } else {
        Player* player = game->getSecondPlayer();
        player->addUnit(unit);
    }
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

