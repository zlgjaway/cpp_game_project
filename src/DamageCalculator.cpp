#include "DamageCalculator.h"
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Main Function
int calculate_damage(const Hand& hand, const vector<int>& chosen_cards) {

  // Obtain Number of Cards Chosen
  int n = chosen_cards.size();

  // Initialize Rank and Element Vectors
  vector<int> ranks;
  vector<int> elements;

  // Extract ranks and elements from Hand
  
for (int i = 0; i < n; i++) {
    Card c = hand.get_card(chosen_cards[i]); // use chosen_cards[i]
    ranks.push_back(c.get_rank());
    elements.push_back(c.get_element());
}


  // Find the right card-checker function to use
  switch (n) {

    // Only 5 Card Scenario will make use of the elements
    case 5: return damage_five_cards(ranks, elements);

    // All are rank-checker functions
    case 4: return damage_four_cards(ranks);
    case 3: return damage_three_cards(ranks);
    case 2: return damage_two_cards(ranks);
    case 1: return 10; 
    default:
        cerr << "Invalid number of chosen cards: " << n << endl;
        return 0;
  }
}


// TWO CARD SCENARIO
int damage_two_cards(const vector<int>& ranks) {
  // If first card matches second card, its a duo!
  if (ranks[0] == ranks[1]) {
    cout << "Duo Attack! 20 Damage Dealt.\n";
    return 20;
  }
  cout << "Solo Attack! 10 Damage Dealt.\n";
  return 10;
}


// THREE CARD SCENARIO
int damage_three_cards(const vector<int>& ranks) {

  // Stores key-value pairs
  // Basically it every uniquely-ranked card is stored once
  // [1, 2, 2]  ->  1 and 2 stored
  unordered_map<int, int> freq;

  // Going through every rank(r) 
  for (size_t i = 0; i < ranks.size(); i++) {
    freq[ranks[i]]++;
  }
  // i is your loop index, starting from 0
  // ranks.size() gives the number of elements in the ranks vector
  // Loop continues until i reaches ranks.size()
  // size_t is used because vector::size() returns a size_t, so this avoids signed/unsigned comparison warnings
  
  // all cards have the same rank, only 1 unique-ranked card stored
  if (freq.size() == 1) {
    cout << "Triad Attack! 40 Damage Dealt.\n";
    return 40;
  } 

  // There are 2 unique-ranked cards, only 2 of the 3 cards have similar rank
  if (freq.size() == 2) {
    cout << "Duo Attack! 20 Damage Dealt.\n";
    return 20;
  }

  // all 3 unique cards, no damage
  cout << "Solo Attack! 10 Damage Dealt.\n";
  return 10;
}


// FOUR CARD SCENARIO
int damage_four_cards(const vector<int>& ranks) {
  unordered_map<int, int> freq;
  for (size_t i = 0; i < ranks.size(); i++) {
    freq[ranks[i]]++;
  }

  // There is only a frequency of a single number out of the 4 cards (which means they all have the same number)
  if (freq.size() == 1) {
      cout << "Tetrad Attack! 400 Damage Dealt.\n";
      return 400;
  }

  if (freq.size() == 2) {
    bool hasThree = false;

    // Checking if there’s any rank that appears exactly 3 times
    for (const auto& kv : freq) {
      if (kv.second == 3) {
        hasThree = true;
      }
    }
    // Loops through each key-value pair in the map
    // kv.first → the key (the rank number)
    // kv.second → the value (the count/frequency of that rank)
  
    // auto -> automatically deduces the type (pair<const int, int>)
    // & -> avoids copying the pair (better performance)
    // const -> means no modifying the map entry

    if (hasThree) {
        cout << "Triad Attack! 80 Damage Dealt.\n";
        return 80;
    }
    cout << "Duo Set! 40 Damage Dealt.\n";
    return 40;
  }

  if (freq.size() == 3) {
      cout << "Duo Attack! 20 Damage Dealt.\n";
      return 20;
  }

  cout << "Solo Attack! 10 Damage Dealt.\n";
  return 10;
}


// FIVE CARD SCENARIO
int damage_five_cards(const vector<int>& ranks, const vector<int>& elements) {
  unordered_map<int, int> rankFreq;
  unordered_map<int, int> elemFreq;


  for (int i = 0 ; i < ranks.size(); i++) {
      rankFreq[ranks[i]]++;
  }

  for (int i = 0; i < elements.size(); i++) {
    elemFreq[elements[i]]++;
  }

  // Check if all elements are the same
  bool allSameElem = false;
  for (const auto& kv : elemFreq) {
    int rank = kv.first;
    int count = kv.second;

    if (count == 5) {
      allSameElem = true;
      break;
    }
  }
  // looping through the elemFreq table
  // then checking to see whether the second index (number of times a number show up) is == 5
  // which means it checking whether the no. of times the element appear IS 5

  // Sort Ranks
  vector<int> sortedRanks = ranks;
  sort(sortedRanks.begin(), sortedRanks.end());

  bool sequential = true; // DEFAULT: sequence is true 
  // Check to see if sequence condition is met
  for (size_t i = 1; i < sortedRanks.size(); i++) {
    if (sortedRanks[i] != sortedRanks[i-1] + 1) {
      sequential = false;
      break;
    }
  }
  

  // If All Same Element + In-Sequence + Specific Ranks (10 to 14)
  if (allSameElem) {
    if (sequential && sortedRanks == vector<int>({10,11,12,13,14})) {
        cout << "Demon's Hand! 2000 Damage Dealt.\n";
        return 2000;
    }
    if (sequential) {
        cout << "Marching Horde! 600 Damage Dealt.\n";
        return 600;
    }
    cout << "Horde Attack! 125 Damage Dealt.\n";
    return 125;
  }

  // If only Sequential condition met
  if (sequential) {
    cout << "March Attack! 100 Damage Dealt.\n";
    return 100;
  }

  // Check rank combos (As usual the rank matches only)
  bool hasThree = false, hasTwo = false;
  // if there is 3 counts(c) of the number(r) hasThree = true;
  for (const auto& kv : rankFreq) {
    int c = kv.second;
    if (c == 3) hasThree = true;
    if (c == 2) hasTwo = true;
  }

  // Special condition: a triad (3 cards of the rank) and a duo
  if (hasThree && hasTwo) {
    cout << "Grand Warhost! 200 Damage Dealt.\n";
    return 200;
  }

  if (hasFour(rankFreq)) {
    cout << "Tetrad Attack! 400 Damage Dealt.\n";
    return 400;
  }

  if (hasThree) {
    cout << "Triad Attack! 80 Damage Dealt.\n";
    return 80;
  }

  if (hasTwo) {
    cout << "Duo Attack! 20 Damage Dealt.\n";
    return 20;
  }

  cout << "Solo Attack! 10 Damage Dealt.\n";
  return 10;
}


// This Function is used in damage_five_cards
// Find a Tetread (4 cards of the same rank)
bool hasFour(const unordered_map<int,int>& freq) {
  for (const auto& kv : freq) {
    if (kv.second == 4) return true;
  }
  return false;
}