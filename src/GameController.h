#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Deck.h"
#include "Player.h"
#include "Boss.h"
#include "Hand.h"
#include "Orge.h"
#include "Button.h"
class GameController {
public:
    GameController();
    void startGame();

private:
    // Turn flow
    void playerTurn();
    void bossTurn();
    void checkVictoryConditions();
    Orge boss;
    // Helpers
    void repositionHand();   // operates on 'player'
    void onSortElement();
    void onSortRank();
    void onPlayClicked();


    // State
    sf::RenderWindow window;
    Deck   deck;
    Player player;
    int    turnCounter{0};
    bool   gameOver{false};
    
    // NEW: UI members
    sf::Font uiFont;
    Button btnSortElement;
    Button btnSortRank;
    Button btnPlay;

    
    // NEW: UI setup + actions (C++11-friendly, using std::bind)
    void initUI();
    void updateButtonLayout();




};




#endif