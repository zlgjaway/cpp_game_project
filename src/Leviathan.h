#ifndef LEVIATHAN_H
#define LEVIATHAN_H
#include "Hand.h"
#include "Boss.h"
#include "Player.h"
#include "Deck.h"

class Leviathan : public Boss {
public:
    Leviathan();
    ~Leviathan();

    void create() override;
    void deal_boss_damage(Player& p, Deck& deck);  // Overloaded to include deck
    void specialAbility(Player& p, Deck& deck);    // Floods the player's hand
    
    using Boss::deal_boss_damage;
    using Boss::specialAbility;

};

#endif