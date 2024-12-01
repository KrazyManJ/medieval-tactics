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

    void switchActivePlayer();

    Map* getMap();

    Player* getPlayer1();
    Player* getPlayer2();
    Player* getPlayerOnTurn();
    Player* getOponentPlayerOfPlayerOnTurn();

    ~Game();
};

#endif // GAME_H