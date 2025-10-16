#include "GameController.h"
#include <iostream>

int main() {
    std::cout << "[Main] Starting game...\n";
    GameController game;
    std::cout << "[Main] GameController initialized.\n";
    game.startGame();
    std::cout << "[Main] Game ended.\n";
    return 0;
}