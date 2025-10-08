#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
  private:
    int deck_size;
    Card* deck;
  public:
    Deck();
    ~Deck();

    // Creating the Deck
    void create();

    // Shuffle the Deck 
    void shuffle();
};

#endif