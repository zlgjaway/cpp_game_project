#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Deck.h"
#include "Player.h"
#include "Boss.h"
#include "Hand.h"

class GameController {
public:
    GameController();
    void startGame();

private:
    // Turn flow
    void playerTurn();
    void bossTurn();
    void checkVictoryConditions();

    // Helpers
    void repositionHand();   // operates on 'player'

    // State
    sf::RenderWindow window;
    Deck   deck;
    Player player;
    Boss   boss;
    int    turnCounter{0};
    bool   gameOver{false};
};

#endif