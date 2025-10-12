#ifndef CHARACTER_H
#define CHARACTER_H

#include "Damageable.h"

// Abstract base class for any character with health
class Character : public Damageable {
protected:
    int health; // Shared health attribute
public:
    Character(int hp);
    int getHealth() const;
    virtual void takeDamage(int dmg) = 0; // Still abstract
    virtual ~Character();
};

#endif