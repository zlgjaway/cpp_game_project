#include "GameMenu.h"
#include <iostream>

GameMenu::GameMenu(sf::RenderWindow& win) : window(win) {
    
    font.loadFromFile("../assets/fonts/Roboto-Regular.ttf");
    setupUI();
}

void GameMenu::setupUI() {
    boss1Button.setup(font, "Fight ORGE", {100, 200}, {200, 50});
    boss2Button.setup(font, "Fight PHOENIX", {100, 300}, {200, 50});
    boss3Button.setup(font, "Fight LEVIATHAN", {100, 400}, {200, 50});
}

int GameMenu::show() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                if (boss1Button.box.getGlobalBounds().contains(mousePos)) return 1;
                if (boss2Button.box.getGlobalBounds().contains(mousePos)) return 2;
                if (boss3Button.box.getGlobalBounds().contains(mousePos)) return 3;
            }
        }
        
        window.clear(sf::Color::Black);
        boss1Button.draw(window);
        boss2Button.draw(window);
        boss3Button.draw(window);
        window.display();
    }

    return -1; // window closed
}