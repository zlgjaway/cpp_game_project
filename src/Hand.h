#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include "Deck.h"

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

    // Fill the Hand
    void fillFromDeck(Deck &deck);
    // Find which slots are empty, and replace the slots
    void replace(int* chosen_cards, int chosen_size, Deck &deck);

    void sortByRank();

    void sortByElement();

    Card get_card(int index) const;
    void set_card(int index, const Card& card);
};

#endif