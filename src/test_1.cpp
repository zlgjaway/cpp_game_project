#include <iostream>
#include "Deck.h"
using namespace std;

int main() {
  // Creating the Deck
  Deck deck;
  deck.create();
  cout << "Created deck of 52 cards.\n";

  // Shuffle Deck
  deck.shuffle();
  cout << "Deck shuffled.\n";

  // Drawing the first 7 cards
  cout << "Drawing 7 cards:\n";
  for (int i = 0; i < 7; ++i) {
    // Print each individual card
    Card c = deck.draw();
    cout << "Card " << i + 1
          << ": Rank " << c.get_rank()
          << ", Element " << c.get_element()
          << endl;
  }

  cout << "All tests executed.\n";
  return 0;
}
