#include "Card.h"

Card::Card() {
  rank = 0;
  element = 0;
}

Card::Card(int rank, int element) {
  this->rank = rank;
  this->element = element;
}

int Card::get_rank() const {
  return rank;
}

int Card::get_element() const {
  return element;
}

void Card::set_rank(int rank) {
  this->rank = rank;
}

void Card::set_element(int element) {
  this->element = element;
}
bool Card::loadModel(const std::string &filepath){
   if (!texture.loadFromFile(filepath)) return false;
        sprite.setTexture(texture);
        return true;
}
sf::Sprite& Card::getSprite(){
    return sprite; 
}
void Card::setPosition(float x, float y){
    sprite.setPosition(x, y);
};

sf::Vector2f Card::getPosition()const {
  return sprite.getPosition();
};