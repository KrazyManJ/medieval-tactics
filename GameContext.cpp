#include "GameContext.h"


GameContext::GameContext(QObject *parent)
    : QObject{parent}
{}

Q_INVOKABLE void GameContext::createNewGame() {
    // ignore potential memory leak - solved by using singleton
    new Game();
}
