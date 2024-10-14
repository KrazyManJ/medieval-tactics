#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include "Dictionary.hpp"

using namespace std;

class Game {
private:
    Dictionary* dict;
public:
    Game();
    void printIntro() const;
    void startLoop() const;
};

#endif /* Game_hpp */
