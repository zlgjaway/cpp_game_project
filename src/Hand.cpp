#include "Hand.h"
#include "Deck.h"
#include <iostream>
#include <algorithm> // for sort()


Hand::Hand() {
  hand_size = 7;
  std::cout << "[Hand] Default constructor called. Allocating " << hand_size << " cards.\n";
  hand = new Card[hand_size];
}

Hand::Hand(int hand_size) {
  this->hand_size = hand_size;
  std::cout << "[Hand] Param constructor called. Allocating " << hand_size << " cards.\n";
  hand = new Card[hand_size];
}





void Hand::fillFromDeck(Deck &deck) {
    std::cout << "[Hand] fillFromDeck() called. Hand size: " << hand_size << "\n";
    for (int i = 0; i < hand_size; i++) {
        std::cout << "[Hand] Drawing card " << i << "\n";
        hand[i] = deck.draw(); // likely crash point
        std::cout << "[Hand] Card " << i << " assigned.\n";
    }
    std::cout << "[Hand] fillFromDeck() finished.\n";
}


// Find which slots are empty, and replace the slots
void Hand::replace(int* chosen_cards, int chosen_size, Deck &deck) {
  for (int i = 0; i < chosen_size; i++) {
    // Find the index of card chosen (in the hand)
    int index = chosen_cards[i];

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

Card Hand::get_card(int index) const {
  return hand[index]; 
}

void Hand::set_card(int index, const Card& card) {
  hand[index] = card;
}

int Hand::getSize() const {
    return hand_size;
}

Card& Hand::get_card(int index) {
    return hand[index];
}

Hand::~Hand() {
  delete[] hand;
}
