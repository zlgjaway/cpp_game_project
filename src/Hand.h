#ifndef HAND_H
#define HAND_H

#include "Card.h"

class Hand {
  private:
    int hand_size;
    Card* hand;
  public:
    // Default of 7 Cards
    Hand();
    // Incase user gets a sigil buff (Extended Cards)
    Hand(int hand_size);
    // Deconstructor
    ~Hand();

    // Find which slots are empty, and replace the slots
    void replace(int* chosen_cards, int chosen_size, Deck &deck);

};

#endif