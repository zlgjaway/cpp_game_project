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
  for (int set = 1; set < 5; set++) { // set fire = 1 / wind = 2 / earth = 3 / water = 4
    for (int card_rank = 2; card_rank < 15; card_rank++) {
      deck[index] = Card(card_rank, set); \

      // Build the file path dynamically
      std::string filepath = "../assets/Element deck/" +                           
                            std::to_string(card_rank) + "-" +
                            std::to_string(set) + ".png";

      // Load the image
      deck[index].loadModel(filepath);

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


Card& Deck::operator[](int index) {
    if (index < 0 || index >= deck_size)
        throw std::out_of_range("Deck index out of range");
    return deck[index];
}

const Card& Deck::operator[](int index) const {
    if (index < 0 || index >= deck_size)
        throw std::out_of_range("Deck index out of range");
    return deck[index];
}


bool Deck::isEmpty() const {
    return cards_used >= deck_size;
}


int Deck::size() const {
    return deck_size - cards_used;
}
