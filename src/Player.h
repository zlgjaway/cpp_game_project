#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include "Character.h"

using namespace std;

// Forward declarations
class Deck;
class Card;
class Hand;

// Player inherits from Character
class Player : public Character {
private:
    Hand* hand;                // Pointer to player's hand (placeholder)
    vector<string> sigils;     // Player's special abilities
    int maxHandSize;           // Max number of cards
public:
    Player(int hp = 100, int maxHand = 7);
    void drawCards(Deck& deck);
    void selectCards(vector<Card> selected);
    void takeDamage(int dmg) override;
};

#endif