#include "Game.h"

#include <AttackUnit.h>
#include <Unit.h>

Game::Game() {
    if (Game::instance != nullptr)
        delete Game::instance;
    Game::instance = this;
    map = new Map();

    firstPlayer = new Player(FIRST_PLAYER_COLOR, START_MONEY);
    firstPlayer->addUnit(new AttackUnit(1.0,1,2,1,1,{GroundType::Grass},{.row=2,.column=4},5,"Warrior","This is warrior, now he just moves"));
    firstPlayer->addUnit(new AttackUnit(1.0,1,1,1,1,{GroundType::Grass},{.row=1,.column=3},5,"Druid","This is knight, now he just moves"));

    secondPlayer = new Player(SECOND_PLAYER_COLOR, START_MONEY);
    secondPlayer->addUnit(new AttackUnit(1.0,1,1,1,1,{GroundType::Grass},{.row=1,.column=1},5,"Priest","This is warrior, now he just moves"));
    secondPlayer->addUnit(new AttackUnit(1.0,1,1,1,1,{GroundType::Grass},{.row=4,.column=1},5,"Warrior","This is knight, now he just moves"));

    firstPlayerOnTurn = true;
    turns = 0;
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
    if (!map->isInRange(row,column))
        throw std::logic_error("Action out of map");
    if (map->getObjectAt(row,column)->isSolid())
        throw std::logic_error("Cannot move into solid object");
    getPlayerOnTurn()->moveSelectedUnit(row,column);
    markTurn();
}

void Game::useUnitAbilityOfCurrentPlayer(int row, int column) {
    if (!map->isInRange(row,column))
        throw std::logic_error("Action out of map");
    if (map->getObjectAt(row,column)->isSolid())
        throw std::logic_error("Cannot move into solid object");
    getPlayerOnTurn()->useSelectedUnit(row, column);
    markTurn();
}

void Game::markTurn() {
    turns++;
    if (turns == TURNS_PER_ROUND) {
        getPlayerOnTurn()->deselectUnit();
        firstPlayerOnTurn = !firstPlayerOnTurn;
        turns = 0;
    }
}

int Game::getRemainingTurns() {
    return TURNS_PER_ROUND - turns;
}

Game::~Game() {
    delete map;
    delete firstPlayer;
    delete secondPlayer;
}
