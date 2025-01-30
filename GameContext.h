#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

#include "Game.h"
#include <QSize>

#include <QObject>

class GameContext : public QObject
{
    Q_OBJECT
public:
    explicit GameContext(QObject *parent = nullptr);

    Q_INVOKABLE void createNewGame();

    Q_INVOKABLE QVariantMap getMapDetails();

    Q_INVOKABLE QVariant getUnitByPos(int row, int column);

    Q_INVOKABLE QVariant getCurrentPlayerOnTurn();

    Q_INVOKABLE void selectUnitOfCurrentPlayer(int row, int column);

    Q_INVOKABLE void selectButyingUnitInShop(const QString& unitName);

    Q_INVOKABLE QVariant getSelectedUnitOfCurrentPlayer();

    Q_INVOKABLE bool canUnitOfCurrentPlayerWalkToDest(int destRow, int destColumn);

    Q_INVOKABLE void moveUnitOfCurrentPlayer(int destRow, int destColumn);

    Q_INVOKABLE int getRemainingTurns();

    Q_INVOKABLE QVariant getMapObjectAt(int row, int column);

    Q_INVOKABLE QVariant getShopDetails();

    Q_INVOKABLE void buyUnitForPlayer(int row, int column);

    Q_INVOKABLE bool isShopReady();

    Q_INVOKABLE void playerReady();

    Q_INVOKABLE void deselectShopUnit();

    Q_INVOKABLE void useUnitOfCurrentPlayer(int destRow, int destColumn);

    Q_INVOKABLE int getPlayerMoney();

    Q_INVOKABLE bool isGameOver();

    Q_INVOKABLE bool canUseAbilityOnDest(int destRow, int destColumn);

    Q_INVOKABLE QString getWinner();
signals:
};

#endif // GAMECONTEXT_H
