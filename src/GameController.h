#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <SFML/Graphics.hpp>
#include "Deck.h"
#include "Player.h"
#include "Boss.h"
#include "Hand.h"
#include "Orge.h"
#include "Phoenix.h"
#include "Button.h"
#include "DamageCalculator.h"
#include "GameMenu.h"
#include "Leviathan.h"
class GameController {
public:
    GameController();
    ~GameController();  // Add destructor to clean up boss
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
    Boss* boss = nullptr;  //null pointer
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