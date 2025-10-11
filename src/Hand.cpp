#include "Hand.h"
#include "Deck.h"

#include <algorithm> // for sort()

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
void Hand::replace(int* chosen_cards, int chosen_size, Deck deck) {
  for (int i = 0; i < chosen_size; i++) {
    // Find the index of card chosen (in the hand)
    int index = chosen_cards[i] - 1;

    // Replace the "empty" slot
    hand[index] = deck.draw();
  }
}

void Hand::sortByRank() {
    std::sort(hand, hand + hand_size, [](const Card &a, const Card &b) {
        return a.get_rank() < b.get_rank();
    });
}

void Hand::sortByElement() {
    std::sort(hand, hand + hand_size, [](const Card &a, const Card &b) {
        return a.get_element() < b.get_element();
    });
}