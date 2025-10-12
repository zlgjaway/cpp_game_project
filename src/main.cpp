#include <SFML/Graphics.hpp>
#include "Deck.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML Card Deck");

    Deck deck;
    deck.create();
    deck.shuffle();

    // Position cards in a grid for demo
    int x = 50, y = 50;
    for (int i = 0; i < 52; ++i) {
        deck[i].setPosition(x, y);
        x += 80;
        if (x > 900) { x = 50; y += 120; }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(30, 100, 30)); // green table

        // Draw all cards
        for (int i = 0; i < 52; ++i)
            window.draw(deck[i].getSprite());

        window.display();
    }

    return 0;
}
