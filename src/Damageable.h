#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

// Interface for anything that can take damage
class Damageable {
public:
    virtual void takeDamage(int dmg) = 0; // Pure virtual function
    virtual ~Damageable() = default;      // Virtual destructor for cleanup
};

#endif