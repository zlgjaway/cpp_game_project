#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "Deck.h"
#include "Hand.h"
#include "Boss.h"
#include "DamageCalculator.h"

// Seperate Functions
#include "welcome_display.h"
#include "display_game_status.h"
#include "view_options.h"
#include "select_cards.h"

// TODO: include Boss.h once you create it

using namespace std;

int main() {
  srand(static_cast<unsigned>(time(nullptr)));

  // Welcome
  welcome_display();

  // Create a Standard Boss
  Boss boss(100, 3, 300);

  int user_health = 100;
  int current_turn = 0;
  int cards_taken = 0;

  // === Create and shuffle deck ===
  Deck deck;
  deck.create();
  deck.shuffle();

  // === Draw initial hand ===
  Hand player_hand;
  player_hand.fillFromDeck(deck);
  cards_taken = 7;

  // === MAIN GAME LOOP ===
  while (true) {
    current_turn++;

    // Sort player's hand
    Hand player_hand_rank = player_hand;
    player_hand_rank.sortByRank();

    Hand player_hand_elem = player_hand;
    player_hand_elem.sortByElement();

    // Display current state
    display_game_status(player_hand, user_health, boss.get_boss_health(), boss.get_boss_damage(), boss.get_boss_turn(), current_turn, cards_taken);

    // Let player view/switch view of hand (rank/suit/original)
    view_options(player_hand, player_hand_rank, player_hand_elem, user_health, boss.get_boss_health(), boss.get_boss_damage(), boss.get_boss_turn(), current_turn, cards_taken);

    // Player selects cards
    vector<int> chosen_cards = select_cards(player_hand);
    cout << "=========================" << endl;

    // Damage calculation
    int n = chosen_cards.size();

    int card_damage;
    card_damage =  calculate_damage(player_hand, chosen_cards);

    // Apply damage
    boss.take_damage_boss(card_damage);
    display_game_status(player_hand, user_health, boss.get_boss_health(), boss.get_boss_damage(), boss.get_boss_turn(), current_turn, cards_taken);

    // Check win condition
    if (boss.get_boss_health() <= 0) {
      cout << "\nCongrats, Champion. The Boss is Defeated!\n";
      break;
    }

    // Boss attacks every few turns
    if (current_turn % boss.get_boss_turn() == 0) {
      current_turn = 0;
      user_health -= boss.get_boss_damage();
      cout << "\nBoss retaliates, dealing " << boss.get_boss_damage() << " damage. You have " << user_health << " health left.\n";
      string cont;
      cout << "Type anything to continue: ";
      cin >> cont;
    }

    // Check lose condition
    if (user_health <= 0) {
        cout << "\nYou have no health left. Nice try.\n";
        break;
    }

    // Replace used cards
    player_hand.replace(chosen_cards, n, deck);
  }

  return 0;
}