#include "DamageCalculator.h"
#include <stdexcept> // If User doesn't choose between 1-5 cards

using namespace std;

// Calculate Damage Function
int dmg_calc(int* chosen_indices, int chosen_size, Hand& player_hand) {
  if (chosen_size < 1 || chosen_size > 5)
    throw invalid_argument("Chosen size must be between 1 and 5.");

  // Allocate temporary array for chosen cards
  Card* chosen_cards = new Card[chosen_size];

  for (int i = 0; i < chosen_size; i++) {
    int index = chosen_indices[i] - 1;  // assuming 1-based input
    chosen_cards[i] = player_hand.get_card(index);
  }

  // 
  int damage = 0;
  switch (chosen_size) {
  case 5:
      damage = scenario_5cards(chosen_cards, chosen_size);
      break;
  case 4:
      damage = scenario_4cards(chosen_cards, chosen_size);
      break;
  case 3:
      damage = scenario_3cards(chosen_cards, chosen_size);
      break;
  case 2:
      damage = scenario_2cards(chosen_cards, chosen_size);
      break;
  case 1:
      cout << "Solo attack! 10 damage dealt.\n";
      damage = 10;
      break;
  }

  delete[] chosen_cards;
  return damage;
}


// THE SCENARIO FUNCTIONS (OUTPUT -> DAMAGE) FUNCTION DECIDES THE DAMAGE AFTER CHECKING

int scenario_5cards(Card* chosen_cards, int chosen_size) {
  cout << "Checking 5-card combo...\n";
  return 0;
}

int scenario_4cards(Card* chosen_cards, int chosen_size) {
  cout << "Checking 4-card combo...\n";
  return 0;
}

int scenario_3cards(Card* chosen_cards, int chosen_size) {
  cout << "Checking 3-card combo...\n";
  return 0;
}

int scenario_2cards(Card* chosen_cards, int chosen_size) {
  cout << "Checking 2-card combo...\n";
  return 0;
}