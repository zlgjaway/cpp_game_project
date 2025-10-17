
#ifndef BOSS_H
#define BOSS_H

#include "Character.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class Boss : public Character {
protected:
    int baseDamage;
    int attackInterval;
    int turnCounter;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Boss(int hp = 100, int baseDmg = 10, int interval = 2);
    virtual ~Boss() = default;

    virtual void takeDamage(int dmg) override;
    virtual void deal_boss_damage(Player& p);
    virtual void specialAbility(Player& p);

    virtual void create(); // New virtual method
    bool load_model(const std::string& filepath);
    const sf::Sprite& getSprite() const { return sprite; }
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
};

#endif
