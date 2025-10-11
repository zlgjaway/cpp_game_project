#include "Player.h"

Player::Player(int hp, int maxHand)
    : Character(hp), maxHandSize(maxHand), hand(nullptr) {}



void Player::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
    cout << "Player takes " << dmg << " damage. HP now: " << health << endl;
}