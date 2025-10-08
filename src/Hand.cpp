#include "Hand.h"
#include "Deck.h"

Hand::Hand() {
  hand_size = 7;
  hand = new Card[hand_size];
}

Hand::Hand(int hand_size) {
  this->hand_size = hand_size;
  hand = new Card[hand_size];
}

Hand::~Hand() {
  delete[] hand;
}

// Find which slots are empty, and replace the slots
void Hand::replace(int* chosen_cards, int chosen_size, Deck &deck) {
  for (int i = 0; i < chosen_size; i++) {
    int index = chosen_cards[i] - 1; // assuming 1-based input
    hand[index] = deck.draw();       // draw() should return a new Card
  }
}