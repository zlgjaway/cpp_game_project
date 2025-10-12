#include "Character.h"

Character::Character(int hp) : health(hp) {}

int Character::getHealth() const {
    return health;
}

Character::~Character() = default;