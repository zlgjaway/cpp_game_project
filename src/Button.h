#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>

struct Button {
    sf::RectangleShape box;
    sf::Text label;
    std::function<void()> onClick = nullptr;  // callable, default = null

    void setup(const sf::Font& font,
               const std::string& text,
               sf::Vector2f pos,
               sf::Vector2f size,
               sf::Color bg = sf::Color(50, 50, 50),
               sf::Color fg = sf::Color::White)
    {
        box.setPosition(pos);
        box.setSize(size);
        box.setFillColor(bg);
        box.setOutlineColor(sf::Color(200, 200, 200));
        box.setOutlineThickness(2.f);

        label.setFont(font);
        label.setString(text);
        label.setCharacterSize(18);
        label.setFillColor(fg);

        const auto bounds = label.getLocalBounds();
        float lx = pos.x + (size.x - bounds.width) / 2.f - bounds.left;
        float ly = pos.y + (size.y - bounds.height) / 2.f - bounds.top - 4.f;
        label.setPosition(lx, ly);
    }

    bool contains(sf::Vector2f p) const {
        return box.getGlobalBounds().contains(p);
    }

    void setHover(bool hover) {
        box.setFillColor(hover ? sf::Color(70, 70, 70) : sf::Color(50, 50, 50));
    }

    void draw(sf::RenderWindow& w) const {
        w.draw(box);
        w.draw(label);
    }
};