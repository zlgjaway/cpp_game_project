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

  bool quit_view_options = false;

  while (!quit_view_options) {
    cout << "\nView hand in other arrangements? (y/n): ";
    string view_options_input;
    getline(cin, view_options_input);
    transform(view_options_input.begin(), view_options_input.end(), view_options_input.begin(), ::tolower);
    view_options_input.erase(remove_if(view_options_input.begin(), view_options_input.end(), ::isspace), view_options_input.end());

    if (view_options_input == "n") {
      quit_view_options = true;
    }

    else if (view_options_input == "y") {
      cout << "\n=== Sort Hand Options ===\n\n";
      cout << "1 - Original Hand\n";
      cout << "2 - Sort by Rank\n";
      cout << "3 - Sort by Symbol\n";
      cout << "4 - Ready to Select Cards\n";
      cout << "=========================\n\n";

      cout << "Select (1/2/3/4): ";
      string input;
      getline(cin, input);
      int view_mode = stoi(input);

      if (view_mode < 1 || view_mode > 4) {
          cout << "Invalid choice (1-4 only)\n";
          continue;
      }

      switch (view_mode) {
        case 1:
          player_hand = player_hand;
          display_game_status(player_hand, user_health, boss_health, boss_damage, attack_turn, current_turn, cards_taken);
          break;

        case 2:
          player_hand = player_hand_rank;
          display_game_status(player_hand, user_health, boss_health, boss_damage, attack_turn, current_turn, cards_taken);
          break;

        case 3:
          player_hand = player_hand_elem;
          display_game_status(player_hand, user_health, boss_health, boss_damage, attack_turn, current_turn, cards_taken);
          break;

        case 4:
          quit_view_options = true;
          break;
      }
    } 
    else { cout << "Type y or n only.\n";}
  }
}