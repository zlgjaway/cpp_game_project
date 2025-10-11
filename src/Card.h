#ifndef CARD_H
#define CARD_H
#include <SFML/Graphics.hpp>
#include <string>

class Card {
  protected:
    // 2-14 (J - 11, Q - 12, K - 13, A - 14)
    int rank;
    // (Fire - 1, Water - 2, Earth - 3, Wind - 4)
    int element;
    sf::Texture texture; // texture for rendering
    sf::Sprite sprite; // sprite for drawing
  public:
    Card();
    Card(int rank, int element); 

    int get_rank() const;
    int get_element() const;

    void set_rank(int rank);
    void set_element(int element);
    // Load the texture from file and assign to sprite

    bool loadModel(const std::string &filepath);
    sf::Sprite& getSprite();
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
};

#endif