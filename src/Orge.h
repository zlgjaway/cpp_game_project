#ifndef ORGE_H
#define ORGE_H

#include "Boss.h"

class Orge : public Boss {
public:
    Orge();  // Constructor
    ~Orge(); // Destructor

    void create() override; // Loads sprite
    void deal_boss_damage(Player& p) override;
    void specialAbility(Player& p) override;
};

#endif // ORGE_H