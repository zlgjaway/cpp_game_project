#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <SFML/Graphics.hpp>
#include "Button.h"

class GameMenu {
public:
    GameMenu(sf::RenderWindow& window);
    int show(); // returns selected boss ID

private:
    sf::RenderWindow& window;
    sf::Font font;
    Button boss1Button;
    Button boss2Button;
    Button boss3Button;

    void setupUI();
};

#endif