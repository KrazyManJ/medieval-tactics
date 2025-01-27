#include "Game.h"

#include <AttackUnit.h>
#include <Unit.h>
#include "Shop.h"

Game::Game() {
    if (Game::instance != nullptr)
        delete Game::instance;
    Game::instance = this;
    map = new Map();
    shop = new Shop();

    firstPlayer = new Player(FIRST_PLAYER_COLOR, START_MONEY);

    secondPlayer = new Player(SECOND_PLAYER_COLOR, START_MONEY);

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

Shop* Game::getShop() { return shop; }

bool Game::isFirstPlayerOnTurn() { return firstPlayerOnTurn; }

Player* Game::getPlayerOnTurn() {
    return (!shop->isReady() ? !shop->isFirstPlayerReady() : isFirstPlayerOnTurn())
       ? firstPlayer
       : secondPlayer;
}

Player* Game::getOponentPlayerOfPlayerOnTurn() {
    return (isFirstPlayerOnTurn()) ? secondPlayer : firstPlayer;
}

void Game::switchActivePlayer() {
    firstPlayerOnTurn = !firstPlayerOnTurn;
}

void Game::moveUnitOfCurrentPlayer(int row, int column) {
    if (!map->isInRange(row,column))
        throw std::logic_error("Action out of map");
    if (map->getObjectAt(row,column)->isSolid())
        throw std::logic_error("Cannot move into solid object");
    if (!shop->isReady())
        throw std::logic_error("Cannot move unit in buying phase");
    getPlayerOnTurn()->moveSelectedUnit(row,column);
    markTurn();
}

void Game::useUnitAbilityOfCurrentPlayer(int row, int column) {
    if (!map->isInRange(row,column))
        throw std::logic_error("Action out of map");
    if (map->getObjectAt(row,column)->isSolid())
        throw std::logic_error("Cannot perform action with solid");
    if (!shop->isReady())
        throw std::logic_error("Cannot use unit in buying phase");
    qDebug() << "performing";
    getPlayerOnTurn()->useSelectedUnit(row, column);
    qDebug() << "marked turn";
    markTurn();
}

void Game::markTurn() {
    if (!shop->isReady()) {
        shop->markReady();
        return;
    }
    turns++;
    if (turns == TURNS_PER_ROUND) {
        getPlayerOnTurn()->deselectUnit();
        firstPlayerOnTurn = !firstPlayerOnTurn;
        turns = 0;
    }
}

int Game::getRemainingRoundTurns() {
    if (!shop->isReady())
        throw std::logic_error("Cannot get remaining rounds when shop is not ready!");
    return TURNS_PER_ROUND - turns;
}

bool Game::isGameOver() {
    if (!shop->isReady()) return false;
    // for (Unit* unit : getFirstPlayer()->getUnits()) {
    //     qDebug() << getFirstPlayer() -> getColor() << unit->getName() << unit->getHp();
    // }
    // for (Unit* unit : getSecondPlayer()->getUnits()) {
    //     qDebug() << getSecondPlayer() -> getColor() << unit->getName() << unit->getHp();
    // }
    // return false;

    for (Player* player : {getFirstPlayer(),getSecondPlayer()}) {
        std::vector<Unit*> units = player->getUnits();
        qDebug() << player->getColor();
        if (
            std::all_of(
                units.begin(),
                units.end(),
                [player](Unit* u){
                    qDebug() << player->getColor() << u->getName() << u->getHp();
                    return u->getHp() <= 0;
                }
            )
        )
        return true;
    }
    return false;
}

Game::~Game() {
    delete map;
    delete firstPlayer;
    delete secondPlayer;
}
