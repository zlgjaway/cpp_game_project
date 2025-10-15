#ifndef CARD_H
#define CARD_H
#include <SFML/Graphics.hpp>
#include <string>

class Card {
  protected:
    int rank;
    int element;
    sf::Texture texture;
    sf::Sprite sprite;

  public:
    bool selected = false; // track if this card is selected

    Card();
    Card(int rank, int element);

    int get_rank() const;
    int get_element() const;

    void set_rank(int rank);
    void set_element(int element);

    bool loadModel(const std::string &filepath);
    sf::Sprite& getSprite();
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;

    void setSelected(bool s); // optional helper
    bool operator==(const Card& other) const;
};

#endif