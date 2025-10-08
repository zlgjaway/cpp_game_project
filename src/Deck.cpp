#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

#include "Deck.h"

Deck::Deck() { 
  // create memory for the deck 
  deck_size = 52;
  deck = new Card[deck_size];
}

Deck::~Deck() {
  for (int i = 0; i < 52; i++) {
    delete deck[i];
  }
  delete deck;
}

// Create the all 52 cards
void create() {
  int index = 0;
  for (int set = 1; set < 5; set++) {
    for (int card_rank = 2; card_rank < 15; card_rank++) {
      deck[index] = Card(card_rank, set);
      index++;
    }
  }
}

// Shuffle the Deck 
void shuffle() {
  // randomizing 
  random_device rd;
  mt19937 gen(rd());
  shuffle(deck.begin(), deck.end(), gen);
}