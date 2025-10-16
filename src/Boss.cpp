#include "Boss.h"
#include <iostream>

Boss::Boss(int hp, int baseDmg, int interval)
    : Character(hp), baseDamage(baseDmg), attackInterval(interval), turnCounter(0) {}

void Boss::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
    std::cout << "Boss takes " << dmg << " damage! HP left: " << health << "\n";
}

void Boss::deal_boss_damage(Player& p) {
    turnCounter++;
    std::cout << "Boss attacks for " << baseDamage << " damage!\n";
    p.takeDamage(baseDamage);

    // Optional: every attackInterval turns, trigger special ability
    if (turnCounter % attackInterval == 0) {
        specialAbility(p);
    }
}

void Boss::specialAbility(Player& p) {
    std::cout << "Boss uses a special attack!\n";
    // Default: extra damage
    p.takeDamage(baseDamage / 2);
}
