#include "Character.h"

// Constructor
Character::Character(int hp) : health(hp) {}

// Destructor
Character::~Character() {}

// Getter
int Character::getHealth() const {
    return health;
}
