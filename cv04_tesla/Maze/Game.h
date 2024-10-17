#ifndef GAME_H
#define GAME_H


#include "Map.h"

class Game {
private:
    Map* map;
    void printIntroduction() const;
    void printOptions() const;
    char waitForInput() const;
    void printEnd() const;
    void processInput(char input);
    void tryMovingWorm(const int x, const int y);

public:
    void start();
    Game();
};


#endif //UNTITLED_GAME_H
