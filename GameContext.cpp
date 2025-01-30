#include "GameContext.h"
#include "Shop.h"


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
            return pos.row == row && pos.column == column && !unit->isDead();
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
    Game::getInstance()->getPlayerOnTurn()->selectUnit(row,column);
}


Q_INVOKABLE int GameContext::getPlayerMoney() {
    return Game::getInstance()->getShop()->getPlayerMoney();
}

Q_INVOKABLE void GameContext::selectButyingUnitInShop(const QString& unitName) {
    Game::getInstance()->getShop()->selectBuyingUnit(unitName.toStdString());
}


Q_INVOKABLE QVariant GameContext::getSelectedUnitOfCurrentPlayer() {
    QVariant ret = QVariant::fromValue(nullptr);
    Player* player = Game::getInstance()->getPlayerOnTurn();
    if (player->hasSelectedUnit())
        ret.setValue(player->getSelectedUnit()->serialize());
    return ret;
}

Q_INVOKABLE bool GameContext::canUnitOfCurrentPlayerWalkToDest(int destRow, int destColumn) {
    auto* game = Game::getInstance();
    Unit* playerUnit = game->getPlayerOnTurn()->getSelectedUnit();
    std::vector<GroundType> groundTypes = playerUnit->getEnterableGroundType();

    return
        playerUnit->isInWalkingRange(destRow,destColumn)
           && std::find(
               groundTypes.begin(),
               groundTypes.end(),
               game->getMap()->getObjectAt(destRow,destColumn)->getType()
            ) != groundTypes.end()
    ;
}

Q_INVOKABLE void GameContext::moveUnitOfCurrentPlayer(int destRow, int destColumn) {
    Game::getInstance()->moveUnitOfCurrentPlayer(destRow,destColumn);
}

Q_INVOKABLE int GameContext::getRemainingTurns() {
    return Game::getInstance()->getRemainingRoundTurns();
}

Q_INVOKABLE QVariant GameContext::getMapObjectAt(int row, int column) {
    return Game::getInstance()->getMap()->getObjectAt(row,column)->serialize();
}

Q_INVOKABLE QVariant GameContext::getShopDetails() {
    return Game::getInstance()->getShop()->serialize();
}

Q_INVOKABLE void GameContext::buyUnitForPlayer(int row, int column){
    Game::getInstance()->getShop()->buyUnitForCurrentPlayer(row,column);
}

Q_INVOKABLE bool GameContext::isShopReady(){
    return Game::getInstance()->getShop()->isReady();
}

Q_INVOKABLE void GameContext::playerReady() {
    Game::getInstance()->getShop()->markReady();
}

Q_INVOKABLE void GameContext::useUnitOfCurrentPlayer(int destRow, int destColumn) {
    Game::getInstance()->useUnitAbilityOfCurrentPlayer(destRow,destColumn);
}

Q_INVOKABLE bool GameContext::isGameOver() {
    return Game::getInstance()->isGameOver();
}

Q_INVOKABLE bool GameContext::canUseAbilityOnDest(int destRow, int destColumn) {
    return Game::getInstance()->getPlayerOnTurn()->getSelectedUnit()->canUseAbilityAt(destRow,destColumn);
}

Q_INVOKABLE void GameContext::deselect() {
    Game::getInstance()->getPlayerOnTurn()->deselectUnit();
}

