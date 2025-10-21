#include "Leviathan.h"
#include <iostream>

Leviathan::Leviathan() : Boss(500, 30, 3, 2) { // heath , base damge, speical attack, normal attack
    std::cout << "[Leviathan] Created with 500 HP, 30 base damage, special skill after 3 attacks, attacks every 2 turns.\n";
    
}

Leviathan::~Leviathan() {
    std::cout << "[Leviathan] Leviathan destroyed.\n";
   
}

void Leviathan::create() {
    std::string filepath = "../assets/PNG/Transperent/Icon8.png";
    if (!load_model(filepath)) {
        std::cerr << "[Leviathan] Failed to load sprite from " << filepath << "\n";
        return;
    }

    sprite.setScale(4.0f, 4.0f);
    setPosition(400, 50);
}

void Leviathan::deal_boss_damage(Player& p, Deck& deck) {
    if (turnCounter % attackInterval == 0 && turnCounter >= attackInterval) {
        if (NoramlAttackCount % SpeicalAttackIterval == 0 && NoramlAttackCount >= SpeicalAttackIterval) {
            specialAbility(p, deck);
        } else {
            std::cout << "[Leviathan] Attacks with tidal wave for " << baseDamage << " damage.\n";
            p.takeDamage(baseDamage);
            NoramlAttackCount++;
        }
    }
    turnCounter++;
}

void Leviathan::specialAbility(Player& p, Deck& deck) {
    std::cout << "[Leviathan] Floods the battlefield! Burning player's hand...\n";

    size_t handSize = p.getHand().getSize();
    std::vector<int> allIndices(handSize);
    for (size_t i = 0; i < handSize; ++i) {
        allIndices[i] = static_cast<int>(i);
    }

    try {
        p.getHand().replace(allIndices.data(), static_cast<int>(handSize), deck);
        std::cout << "[Leviathan] Player's hand replaced with new cards.\n";
    } catch (const std::exception& ex) {
        std::cerr << "[Leviathan] ERROR: Failed to flood hand: " << ex.what() << "\n";
    } catch (...) {
        std::cerr << "[Leviathan] ERROR: Unknown error during flood.\n";
    }
}
