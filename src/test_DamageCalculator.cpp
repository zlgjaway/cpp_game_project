#include "DamageCalculator.h"
#include "Card.h"
#include "Hand.h"
#include "Deck.h"

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main() {

  // Creating Deck + Shuffling
  Deck deck;
  deck.create();
  deck.shuffle();

  // Create player hand and fill with 7 cards
  Hand player_hand;
  for (int i = 0; i < 7; ++i)
    player_hand.set_card(i, deck.draw());

  // Display all cards in hand
  cout << "Player hand:\n";
  for (int i = 0; i < 7; ++i) {
    Card c = player_hand.get_card(i);
    cout << i + 1 << ". Rank: " << c.get_rank()
         << " | Element: " << c.get_element() << endl;
  }

  cout << "=== DAMAGE CALCULATOR TEST ===\n\n";

  // ----------------- TWO CARDS -----------------
  cout << "[TWO CARD TESTS]\n";
  cout << "Same ranks (should be Duo Attack):\n";
  cout << damage_two_cards({5,5}) << "\n\n";

  cout << "Different ranks (should be Solo Attack):\n";
  cout << damage_two_cards({5,8}) << "\n\n";

  // ----------------- THREE CARDS -----------------
  cout << "[THREE CARD TESTS]\n";
  cout << "All 3 cards same rank (Triad)\n";
  cout << damage_three_cards({3,3,3}) << "\n\n";

  cout << "Duo among 3 cards\n";
  cout << damage_three_cards({4,4,2}) << "\n\n";

  cout << "All different cards:\n";
  cout << damage_three_cards({1,2,3}) << "\n\n";

  // ----------------- FOUR CARDS -----------------
  cout << "[FOUR CARD TESTS]\n";
  cout << "Tetrad:\n";
  cout << damage_four_cards({7,7,7,7}) << "\n\n";

  cout << "Duo SET:\n";
  cout << damage_four_cards({8,8,9,9}) << "\n\n";

  cout << "Triad + among 5 cards\n";
  cout << damage_four_cards({10,10,10,5}) << "\n\n";

  // ----------------- FIVE CARDS -----------------
  cout << "[FIVE CARD TESTS]\n";
  cout << "All same element & sequential 10–14 (Demon’s Hand):\n";
  cout << damage_five_cards({10,11,12,13,14}, {1,1,1,1,1}) << "\n\n";

  cout << "All same element & sequential (Marching Horde):\n";
  cout << damage_five_cards({2,3,4,5,6}, {2,2,2,2,2}) << "\n\n";

  cout << "All same element (Horde Attack):\n";
  cout << damage_five_cards({3,7,9,11,13}, {3,3,3,3,3}) << "\n\n";

  cout << "Sequential only (March Attack):\n";
  cout << damage_five_cards({4,5,6,7,8}, {1,2,3,4,1}) << "\n\n";

  cout << "Grand Warhost (Triad + Duo):\n";
  cout << damage_five_cards({9,9,9,10,10}, {1,2,3,1,2}) << "\n\n";

  cout << "Tetrad among 5 cards:\n";
  cout << damage_five_cards({11,11,11,11,3}, {2,3,1,4,2}) << "\n\n";

  cout << "Triad among 5 cards:\n";
  cout << damage_five_cards({8,8,8,4,2}, {1,2,3,4,1}) << "\n\n";

  cout << "Duo among 5 cards:\n";
  cout << damage_five_cards({5,5,1,3,9}, {4,2,3,1,3}) << "\n\n";

  cout << "Everything is Different:\n";
  cout << damage_five_cards({2,4,6,8,10}, {1,2,3,4,2}) << "\n\n";


  
  return 0;
}