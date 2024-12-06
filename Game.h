#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Player.h"


class Game
{
private:
    inline static Game* instance = nullptr;

    Map* map;
    Player* firstPlayer;
    Player* secondPlayer;
    bool firstPlayerOnTurn;
public:

    inline static const std::string FIRST_PLAYER_COLOR = "blue";
    inline static const std::string SECOND_PLAYER_COLOR = "orange";
    inline static const int START_MONEY = 5000;

    Game();
    static Game* getInstance();

    Map* getMap();
    Player* getFirstPlayer();
    Player* getSecondPlayer();

    bool isFirstPlayerOnTurn();
    Player* getPlayerOnTurn();
    Player* getOponentPlayerOfPlayerOnTurn();

    void switchActivePlayer();

    void moveUnitOfCurrentPlayer(int row, int column);
    void useUnitAbilityOfCurrentPlayer(int row, int column);

    ~Game();
};

#endif // GAME_H
