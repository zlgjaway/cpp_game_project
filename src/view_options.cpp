#include "view_options.h"

using namespace std;

void view_options(Hand& player_hand,  
                  Hand& player_hand_rank, 
                  Hand& player_hand_elem,
                  int user_health, 
                  int boss_health, 
                  int boss_damage, 
                  int attack_turn, 
                  int current_turn, 
                  int cards_taken) {

  while (true) {
    cout << "\nView hand in other arrangements? (y/n): ";
    string input;
    getline(cin, input);

    // remove whitespace and make lowercase
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    if (input == "n") break;  // exit the loop
    if (input != "y") {        // invalid input
        cout << "Type y or n only.\n";
        continue;
    }

    // input is "y", show options
    cout << "\n=== Sort Hand Options ===\n";
    cout << "1 - Original Hand\n2 - Sort by Rank\n3 - Sort by Symbol\n4 - Ready to Select Cards\n";
    cout << "=========================\nSelect (1-4): ";

    getline(cin, input);
    int choice = stoi(input);

    switch (choice) {
      case 1:
        display_game_status(player_hand, user_health, boss_health, boss_damage, attack_turn, current_turn, cards_taken);
        break;
      case 2:
        display_game_status(player_hand_rank, user_health, boss_health, boss_damage, attack_turn, current_turn, cards_taken);
        break;
      case 3:
        display_game_status(player_hand_elem, user_health, boss_health, boss_damage, attack_turn, current_turn, cards_taken);
        break;
      case 4:
        return;  // ready to select cards
      default:
        cout << "Invalid choice (1-4 only)\n";
    }
  }
}