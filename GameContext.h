#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

#include "Game.h"
#include <QSize>

#include <QObject>

class GameContext : public QObject
{
    Q_OBJECT
private:
    Game* game;
public:
    explicit GameContext(QObject *parent = nullptr);

    Q_INVOKABLE void createNewGame();
    Q_INVOKABLE QSize getMapSize();


signals:
};

#endif // GAMECONTEXT_H
