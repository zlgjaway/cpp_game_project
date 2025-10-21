
#ifndef BOSS_H
#define BOSS_H

#include "Character.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class Boss : public Character {
public:
    Boss(int hp, int baseDmg, int interval_S, int interval_m);

    virtual ~Boss() = default;

    virtual void create();  // Can be overridden for sprite setup
    virtual void specialAbility(Player& p);  // Override for custom abilities
    virtual void deal_boss_damage(Player& p); // overide meachinc for every boss
    void takeDamage(int dmg);
    bool load_model(const std::string& filepath);
    const sf::Sprite& getSprite() const { return sprite; }
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;

    int getHealth() const { return health; }

protected:
    int baseDamage;
    int attackInterval;
    int SpeicalAttackIterval;
    int turnCounter;
    int NoramlAttackCount;

    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
