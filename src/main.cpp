#include <SFML/Graphics.hpp>
#include "GameController.h"
#include <iostream>
#include <exception>
#include <csignal>

int main() {
    std::set_terminate([]{
        std::cerr << "FATAL: Unhandled exception (std::terminate called).\n";
        std::_Exit(1);
    });

    try {
        GameController game;
        game.startGame();
        // If we ended due to win/lose, consider that success:
        return 0;
    } catch (const std::exception& ex) {
        std::cerr << "FATAL exception: " << ex.what() << "\n";
        return 1;
    } catch (...) {
        std::cerr << "FATAL: Unknown exception.\n";
        return 1;
    }
}