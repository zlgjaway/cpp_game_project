#include "Boss.h"
#include <iostream>

Boss::Boss(int hp, int baseDmg, int interval_S, int interval_m)
    : Character(hp), baseDamage(baseDmg), attackInterval(interval_m), SpeicalAttackIterval(interval_S), turnCounter(0), NoramlAttackCount(0) {
}

void Boss::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
    std::cout << "Boss takes " << dmg << " damage! HP left: " << health << "\n";
}

bool Boss::load_model(const std::string &filepath){
    if (!texture.loadFromFile(filepath)) {
        std::cerr << "[Card] ERROR: Failed to load texture from " << filepath << "\n";
        return false;
    }
    sprite.setTexture(texture);
    std::cout << "[Card] Loaded texture from " << filepath << "\n";
    return true;
}

void Boss::deal_boss_damage(Player& p) {
    

    // Optional: every attackInterval turns, trigger special ability
    if (turnCounter % attackInterval == 0 && turnCounter >= attackInterval) {
        if (NoramlAttackCount % SpeicalAttackIterval ==0 && NoramlAttackCount >= SpeicalAttackIterval)
        {
            specialAbility(p);
        }
        else{
            std::cout << "Boss attacks for " << baseDamage << " damage!\n";
            p.takeDamage(baseDamage);
            NoramlAttackCount ++;
        }
    }
    turnCounter++;
}

void Boss::specialAbility(Player& p) {
    std::cout << "Boss uses a special attack!\n";
    // Default: extra damage
    p.takeDamage(baseDamage / 2);
}


void Boss::create() {
    // Default boss has no sprite
}

void Boss::setPosition(float x, float y) { sprite.setPosition(x, y); }
sf::Vector2f Boss::getPosition() const { return sprite.getPosition(); }
