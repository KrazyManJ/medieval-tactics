#include "GameContext.h"


GameContext::GameContext(QObject *parent)
    : QObject{parent}
{}

Q_INVOKABLE void GameContext::createNewGame() {
    // ignore potential memory leak - solved by using singleton
    new Game();
}

Q_INVOKABLE QVariantMap GameContext::getMapDetails() {
    return Game::getInstance()->getMap()->serialize();
}

Q_INVOKABLE QVariantMap GameContext::getPlayersDetails() {
    QVariantMap obj;
    Game* game = Game::getInstance();
    obj["player1"] = game->getFirstPlayer()->serialize();
    obj["player2"] = game->getSecondPlayer()->serialize();
    return obj;
}
