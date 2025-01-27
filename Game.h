#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Player.h"

class Shop;


class Game
{
private:
    inline static Game* instance = nullptr;
    static constexpr int TURNS_PER_ROUND = 2;

    Map* map;
    Player* firstPlayer;
    Player* secondPlayer;
    Shop* shop;
    bool firstPlayerOnTurn;
    int turns;
public:

    inline static const std::string FIRST_PLAYER_COLOR = "blue";
    inline static const std::string SECOND_PLAYER_COLOR = "orange";
    inline static const int START_MONEY = 5000;

    Game();
    static Game* getInstance();

    Map* getMap();
    Player* getFirstPlayer();
    Player* getSecondPlayer();
    Shop* getShop();

    bool isFirstPlayerOnTurn();
    Player* getPlayerOnTurn();
    Player* getOponentPlayerOfPlayerOnTurn();

    void switchActivePlayer();

    void moveUnitOfCurrentPlayer(int row, int column);
    void useUnitAbilityOfCurrentPlayer(int row, int column);

    void markTurn();
    int getRemainingRoundTurns();
    bool isGameOver();

    ~Game();
};

#endif // GAME_H
