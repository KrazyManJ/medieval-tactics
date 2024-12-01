#include "Game.h"

Game::Game() {
    map = new Map();
    player1 = new Player("blue",5000);
    player2 = new Player("orange",5000);
    isPlayerTwoOnTurn = false;
}

Map* Game::getMap(){
    return map;
}


Player* Game::getPlayerOnTurn() {
    return (isPlayerTwoOnTurn) ? player2 : player1;
}


Player* Game::getOponentPlayerOfPlayerOnTurn() {
    return (isPlayerTwoOnTurn) ? player1 : player2;
}

void Game::switchActivePlayer() {
    isPlayerTwoOnTurn = !isPlayerTwoOnTurn;
}

Game::~Game() {
    delete map;
    delete player1;
    delete player2;
}
