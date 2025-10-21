
#ifndef PHOENIX_H
#define PHOENIX_H
#include "Boss.h"

class Phoenix : public Boss {
public:
    Phoenix();
    ~Phoenix();

    void create() override; // Loads sprite
    void deal_boss_damage(Player& p) override;
    void specialAbility(Player& p) override;
};
#endif 