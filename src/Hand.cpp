#include "Hand.h"
#include <algorithm>
#include <vector>

void Hand::fillFromDeck(Deck& deck) {
    while (cards.size() < 7 && !deck.isEmpty()) {
        cards.push_back(deck.draw());
    }
}

void Hand::removeCards(const std::vector<Card>& selected) {
    for (const auto& card : selected) {
        auto it = std::find(cards.begin(), cards.end(), card);
        if (it != cards.end()) {
            cards.erase(it);
        }
    }
}

void Hand::sortByRank() {
    std::sort(cards.begin(), cards.end(),  {
        return a.get_rank() < b.get_rank();
    });
}

void Hand::sortByElement() {
    std::sort(cards.begin(), cards.end(),  {
        return a.get_element() < b.get_element();
    });
}

void Hand::replace(int* chosen_cards, int chosen_size, Deck& deck) {
    std::vector<Card> toRemove;
    for (int i = 0; i < chosen_size; ++i) {
        int index = chosen_cards[i];
        if (index >= 0 && index < static_cast<int>(cards.size())) {
            toRemove.push_back(cards[index]);
        }
    }
    removeCards(toRemove);
    fillFromDeck(deck);
}

const std::vector<Card>& Hand::getCards() const {
    return cards;
}