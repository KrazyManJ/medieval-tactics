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

Q_INVOKABLE QVariant GameContext::getUnitByPos(int row, int col) {
    QVariant ret = QVariant::fromValue(nullptr);
    Game* game = game->getInstance();

    for (Player* player : {game->getFirstPlayer(),game->getSecondPlayer()}) {
        std::vector<Unit*> units = player->getUnits();
        auto unitIt = std::find_if(units.begin(), units.end(), [row,col](Unit* unit){
            Position pos = unit->getPosition();
            return pos.row == row && pos.column == col;
        });
        if (unitIt == units.end()) continue;

        QVariantMap obj;
        obj["color"] = QString::fromUtf8(player->getColor().c_str());
        obj["unit"] = (*unitIt)->serialize();
        ret.setValue(obj);
        break;
    }

    return ret;
}
