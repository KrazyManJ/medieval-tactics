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

Q_INVOKABLE QVariant GameContext::getUnitByPos(int row, int column) {
    QVariant ret = QVariant::fromValue(nullptr);
    Game* game = game->getInstance();

    for (Player* player : {game->getFirstPlayer(),game->getSecondPlayer()}) {
        std::vector<Unit*> units = player->getUnits();
        auto unitIt = std::find_if(units.begin(), units.end(), [row,column](Unit* unit){
            Position pos = unit->getPosition();
            return pos.row == row && pos.column == column;
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

Q_INVOKABLE QVariant GameContext::getCurrentPlayerOnTurn() {
    return Game::getInstance()->getPlayerOnTurn()->serialize();
}

Q_INVOKABLE void GameContext::selectUnitOfCurrentPlayer(int row, int column) {
    return Game::getInstance()->getPlayerOnTurn()->selectUnit(row,column);
}

Q_INVOKABLE QVariant GameContext::getSelectedUnitOfCurrentPlayer() {
    QVariant ret = QVariant::fromValue(nullptr);
    Unit* unit = Game::getInstance()->getPlayerOnTurn()->getSelectedUnit();
    if (unit != nullptr) ret.setValue(unit->serialize());
    return ret;
}

Q_INVOKABLE bool GameContext::isUnitOfCurrentPlayerInWalkingRange(int destRow, int destColumn) {
    return Game::getInstance()->getPlayerOnTurn()->getSelectedUnit()->isInWalkingRange(destRow,destColumn);
}
