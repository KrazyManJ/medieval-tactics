#include "Game.hpp"

Game::Game() {
    dict = new Dictionary();
}

void Game::printIntro() const {
    cout
        << "Welcome to the game word football!"
        << "Give me a word and I will say another one starting by last character of yours, this will repeat infinitely."
        << endl
        << endl
        << "Enjoy the game!"
    ;
}
