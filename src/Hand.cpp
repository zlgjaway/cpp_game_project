#include "Hand.h"

Hand::Hand() {
  hand_size = 7;
  hand = new Card[hand_size];
}

Hand::Hand(int hand_size) {
  this->hand_size = hand_size;
  hand = new Card[hand_size];
}

Hand::~Hand() {
  for (int i = 0; i < 52; i++) {
    delete hand[i];
  }
  delete hand;
}

// Find which slots are empty, and replace the slots
void Hand::draw(int* chosen_cards) {
  for (int i = 0; i < (chosen_cards_size)) {
    
  }
}