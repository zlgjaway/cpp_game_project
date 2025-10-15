#ifndef BOSS_H
#define BOSS_H

#include "Character.h"
#include "Player.h"

class Boss : public Character {
protected:
    int baseDamage;       // Default damage
    int attackInterval;   // Turns between special attacks
    int turnCounter;      // Track turns passed

public:
    Boss(int hp = 100, int baseDmg = 10, int interval = 2);

    virtual void takeDamage(int dmg) override;   // Override Character
    virtual void deal_boss_damage(Player& p);    // Virtual to allow override
    virtual void specialAbility(Player& p);      // Optional: unique boss skill
};

#endif
