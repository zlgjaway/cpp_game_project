#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
protected:
    int health;
public:
    // inital character
    Character(int hp);
    virtual ~Character();

    virtual void takeDamage(int dmg) = 0;
    int getHealth() const;
};

#endif
