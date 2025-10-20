#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Deck.h"
#include "Player.h"
#include "Boss.h"
#include "Hand.h"
#include "Orge.h"
#include "Button.h"
#include "DamageCalculator.h"

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
    void repositionHand();
    void onSortElement();
    void onSortRank();
    void onPlayClicked();

    // State
    sf::RenderWindow window;
    Deck deck;
    Player player;
    Orge boss;
    int turnCounter{0};
    bool gameOver{false};

    // UI
    sf::Font uiFont;
    Button btnSortElement;
    Button btnSortRank;
    Button btnPlay;

    void initUI();
    void updateButtonLayout();
};

#endif
