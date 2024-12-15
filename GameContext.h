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

    Q_INVOKABLE QVariantMap getPlayersDetails();

    Q_INVOKABLE QVariant getUnitByPos(int row, int col);

signals:
};

#endif // GAMECONTEXT_H
