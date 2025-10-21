#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Hand.h"
using namespace std;

// Ask the user to select 1–5 cards from their hand
vector<int> select_cards(const Hand& player_hand) {
  vector<int> chosen_cards;
  bool valid_input = false;

  while (!valid_input) {
    cout << "\nChoose 1–5 Cards (separate by spaces): ";
    string input_line;
    getline(cin, input_line);

    // Convert input string into numbers
    stringstream ss(input_line);
    int index;
    vector<int> cards_chosen;
    while (ss >> index) {
        cards_chosen.push_back(index);
    }

    // Validate input
    if (cards_chosen.empty() ||
        cards_chosen.size() > 5 ||
        any_of(cards_chosen.begin(), cards_chosen.end(),
                [&](int i) { return i < 1 || i > player_hand.get_hand_size(); })) {
        cout << "\nInvalid input, try again.\n";
        continue;
    }

    // Display selected cards
    cout << "\n=== Your Selection ===\n";
    for (int i : cards_chosen) {
        const Card& card = player_hand[i - 1]; // -1 since displayed indexes start at 1
        cout << i << ": Rank " << card.get_rank()
              << " | Element " << card.get_element() << "\n";
    }
    cout << "=========================\n";

    // Confirm selection
    cout << "\nAre you sure? (y/n): ";
    string confirm;
    getline(cin, confirm);
    transform(confirm.begin(), confirm.end(), confirm.begin(), ::tolower);

    if (confirm == "y") {
        valid_input = true;
        chosen_cards = cards_chosen;
    }
  }

  return chosen_cards;
}