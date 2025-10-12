#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
  protected:
    int deck_size;
    int cards_used;
    Card* deck;
  public:
    Deck();
    ~Deck();

    // Creating the Deck
    void create();

    // Shuffle the Deck 
    void shuffle();

    // Draw cards
    Card draw(); 
    
    //adding overloard and make deck an object array
    Card& operator[](int index);
    const Card& operator[](int index) const;
    


};

#endif