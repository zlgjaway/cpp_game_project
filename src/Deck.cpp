#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

#include "Deck.h"

Deck::Deck() { 
  cards_used = 0;
  // create memory for the deck 
  deck_size = 52;
  deck = new Card[deck_size];
}

Deck::~Deck() {
  delete[] deck;
}

// Create the all 52 cards
void Deck::create() {
  int index = 0;
  for (int set = 1; set < 5; set++) {
    for (int card_rank = 2; card_rank < 15; card_rank++) {
      deck[index] = Card(card_rank, set);
      index++;
    }
  }
}

// Shuffle the Deck 
void Deck::shuffle() {
  // randomizing 
  random_device rd;
  mt19937 gen(rd());
  std::shuffle(deck, deck + deck_size, gen);
}

Card Deck::draw() {
    if (cards_used < deck_size)
        return deck[cards_used++];
    throw runtime_error("Deck empty");
}