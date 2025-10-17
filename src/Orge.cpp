#include "Orge.h"
#include <iostream>

Orge::Orge() : Boss(150, 20, 3) {
    std::cout << "[Orge] Created with 150 HP, 20 base damage, special every 3 turns.\n";
}

Orge::~Orge() {
    std::cout << "[Orge] Orge destroyed.\n"; 
}


void Orge::create() {
    std::string filepath = "../assets/PNG/Transperent/Icon25.png";
    if (!load_model(filepath)) {
        std::cerr << "[Orge] Failed to load boss sprite from " << filepath << "\n";
        return;
    }

    // Scale the sprite to make it larger (e.g., 2x size)
    sprite.setScale(5.0f, 5.0f); // Adjust these values as needed
    int x = 400, y = 50;
    setPosition(x, y);
}


void Orge::deal_boss_damage(Player& p) {
    turnCounter++;
    std::cout << "[Orge] Swings a massive hand for " << baseDamage + 5 << " damage!\n";
    p.takeDamage(baseDamage + 5);

    if (turnCounter % attackInterval == 0) {
        specialAbility(p);
    }
}

void Orge::specialAbility(Player& p) {
    std::cout << "[Orge] Enraged Smash! Deals triple damage!\n";
    p.takeDamage(baseDamage * 3);
}