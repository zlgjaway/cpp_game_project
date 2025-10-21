#include "Phoenix.h"
#include <iostream>

Phoenix::Phoenix() : Boss(200, 30, 2, 2) {
    std::cout << "[Phoenix] Created with 200 HP, 25 base damage.\n";
}

Phoenix::~Phoenix() {
    std::cout << "[Phoenix] Phoenix destroyed.\n";
}

void Phoenix::create() {
    std::string filepath = "../assets/PNG/Transperent/Icon41.png";
    if (!load_model(filepath)) {
        std::cerr << "[Phoenix] Failed to load sprite from " << filepath << "\n";
        return;
    }

    sprite.setScale(4.0f, 4.0f);
    setPosition(400, 50);
}

void Phoenix::deal_boss_damage(Player& p) {
    if (turnCounter >= attackInterval && turnCounter % attackInterval == 0) {  
     
        specialAbility(p);  //  revives if when 
        std::cout << "[Phoenix] Attacks with fire for " << baseDamage << " damage.\n";
        p.takeDamage(baseDamage);
        
    }

    turnCounter++;
}


void Phoenix::specialAbility(Player& p) {
    if (health <=100) {
        std::cout << "[Phoenix] Revives from ashes! HP restored to 200.\n";
        health = 250;
    } 
}

