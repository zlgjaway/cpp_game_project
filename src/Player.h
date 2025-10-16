#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include "Character.h"

using namespace std;

class Deck;
class Card;
class Hand;

class Player : public Character {
private:
    Hand* hand;
    vector<string> sigils;
    int maxHandSize;

public:
    Player(int hp = 100, int maxHand = 7);
    void drawCards(Deck& deck);
    void selectCards(vector<Card> selected);
    void takeDamage(int dmg) override;
    ~Player();
    //Getter
    Hand& getHand() { return *hand; }
};

#endif
