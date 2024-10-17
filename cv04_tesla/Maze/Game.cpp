#include "Game.h"
#include "Map.h"
#include <iostream>

Game::Game() {
    map = new Map();
}

void Game::printIntroduction() const {
    std::cout << "Game started." << std::endl;
}

void Game::printOptions() const {
    std::cout << "Your tesla have " << map->getTesla()->getEnergy() << " energy. Press WASD to move the the tesla: ";
}

char Game::waitForInput() const {
    char input;
    std::cin >> input;
    return input;
}

void Game::printEnd() const {
    std::cout << "Game ended" << std::endl;
}

void Game::start() {
    printIntroduction();

    while (true) {
        map->print();
        printOptions();
        char input = waitForInput();
        processInput(input);
    }
}

void Game::processInput(const char input) {
    if (input == 'q') {
        printEnd();
        exit(0);
    } else if (input == 'a') {
        tryMovingWorm(-1, 0);
    } else if (input == 'd') {
        tryMovingWorm(1, 0);
    } else if (input == 'w') {
        tryMovingWorm(0, -1);
    } else if (input == 's') {
        tryMovingWorm(0, 1);
    } else {
        std::cout << "Unsupported option!" << std::endl;
    }
}

void Game::tryMovingWorm(const int x, const int y) {
    if (map->checkMoveAvailability(x, y)) {
        map->moveTesla(x, y);
    } else {
        std::cout << "You just hit the wall! Take care ;)" << std::endl;
    }
}



