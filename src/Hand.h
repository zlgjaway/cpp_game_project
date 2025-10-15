#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"
#include "Deck.h"

class Hand {
private:
    std::vector<Card> cards;

public:
    void fillFromDeck(Deck& deck);
    void removeCards(const std::vector<Card>& selected);
    void sortByRank();
    void sortByElement();
    void replace(int* chosen_cards, int chosen_size, Deck& deck);
    const std::vector<Card>& getCards() const;
};

#endif // HAND_H