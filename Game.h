#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Player.h"


class Game
{
private:
    Map* map;
    Player* player1;
    Player* player2;
    bool isPlayerTwoOnTurn;
public:
    Game();

    Map* getMap();

    Player* getPlayerOnTurn();
    Player* getOponentPlayerOfPlayerOnTurn();

    void switchActivePlayer();

    ~Game();
};

#endif // GAME_H
