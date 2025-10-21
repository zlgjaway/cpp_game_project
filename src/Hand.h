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
    void replace(const std::vector<int>& chosen_cards, int chosen_size, Deck &deck);

    void sortByRank();

    void sortByElement();

    Card get_card(int index) const;
    void set_card(int index, const Card& card);

    Card& operator[](size_t index) {
      return hand[index];
    }

    const Card& operator[](size_t index) const {
      return hand[index];
    }

    int get_hand_size() const {
      return hand_size;
    }

    Card* get_cards() const {
        return hand;
    }
};

#endif