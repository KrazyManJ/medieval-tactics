#include "GameContext.h"


GameContext::GameContext(QObject *parent)
    : QObject{parent}
{}

Q_INVOKABLE void GameContext::createNewGame() {
    delete game;
    game = new Game();
}

Q_INVOKABLE QSize GameContext::getMapSize() {
    auto* map = game->getMap();
    return QSize(map->getWidth(),map->getHeight());
}
