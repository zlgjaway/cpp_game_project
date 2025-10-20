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
        hand[i].refreshSprite(); // ensure sprite matches sorted card
        std::cout << "[Hand] Card " << i << " assigned.\n";
    }
    
    std::cout << "[Hand] fillFromDeck() finished.\n";
}


// Find which slots are empty, and replace the slots

void Hand::replace(int* chosen_cards, int chosen_size, Deck &deck) {
    std::cout << "[Hand] Replacing " << chosen_size << " card(s)...\n";

    for (int i = 0; i < chosen_size; i++) {
        int index = chosen_cards[i];

        // Draw a new card
        hand[index] = deck.draw();

        // Refresh the sprite to match the new card's rank and element
        hand[index].refreshSprite();

        std::cout << "  -> Card " << index << " replaced with Rank="
                  << hand[index].get_rank() << ", Element="
                  << hand[index].get_element() << "\n";
    }

    logHand("After Refill");
}


void Hand::sortByRank() {
    std::sort(hand, hand + hand_size, [](const Card &a, const Card &b) {
        return a.get_rank() < b.get_rank();
    });
    for (int i = 0; i < hand_size; ++i) {
        hand[i].refreshSprite(); // ensure sprite matches sorted card
    }

}

void Hand::sortByElement() {
    std::sort(hand, hand + hand_size, [](const Card &a, const Card &b) {
        return a.get_element() < b.get_element();
    });
    for (int i = 0; i < hand_size; ++i) {
        hand[i].refreshSprite();
    }

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



void Hand::logHand(const std::string& label) const {
    std::cout << "[Hand Log] " << label << ":\n";
    for (int i = 0; i < hand_size; ++i) {
        const Card& c = hand[i];
        std::cout << "  Card " << i << ": Rank=" << c.get_rank()
                  << ", Element=" << c.get_element() << "\n";
    }
}


Hand::~Hand() {
  delete[] hand;
}