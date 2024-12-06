#include "Game.h"

#include <AttackUnit.h>

Game::Game() {
    if (Game::instance != nullptr)
        delete Game::instance;
    Game::instance = this;
    map = new Map();
    firstPlayer = new Player(FIRST_PLAYER_COLOR,START_MONEY);
    secondPlayer = new Player(SECOND_PLAYER_COLOR,START_MONEY);
    firstPlayerOnTurn = true;
}

Game* Game::getInstance() {
    if (Game::instance == nullptr)
        Game::instance = new Game();
    return Game::instance;
}

Map* Game::getMap(){ return map; }

Player* Game::getFirstPlayer() { return firstPlayer; }

Player* Game::getSecondPlayer() { return secondPlayer; }


bool Game::isFirstPlayerOnTurn() { return firstPlayerOnTurn; }

Player* Game::getPlayerOnTurn() {
    return (isFirstPlayerOnTurn()) ? firstPlayer : secondPlayer;
}

Player* Game::getOponentPlayerOfPlayerOnTurn() {
    return (isFirstPlayerOnTurn()) ? firstPlayer : secondPlayer;
}

void Game::switchActivePlayer() {
    firstPlayerOnTurn = !firstPlayerOnTurn;
}

void Game::moveUnitOfCurrentPlayer(int row, int column) {
    if (true /* TODO: implement Map::isInRange(Position) */)
        throw std::logic_error("Action out of map");
    if (map->getObjectAt(row,column)->isSolid())
        throw std::logic_error("Cannot move into solid object");
    getPlayerOnTurn()->moveSelectedUnit(row,column);
}

void Game::useUnitAbilityOfCurrentPlayer(int row, int column) {
    if (true /* TODO: implement Map::isInRange(Position) */)
        throw std::logic_error("Action out of map");
    if (map->getObjectAt(row,column)->isSolid())
        throw std::logic_error("Cannot move into solid object");
    getPlayerOnTurn()->useSelectedUnit(row, column);
}

Game::~Game() {
    delete map;
    delete firstPlayer;
    delete secondPlayer;
}
