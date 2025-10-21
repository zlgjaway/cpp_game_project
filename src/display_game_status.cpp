#include "display_game_status.h"

using namespace std;

void display_game_status(const Hand& player_hand, int user_health, int boss_health, int BOSS_DAMAGE, int ATTACK_TURN, int current_turn, int cards_taken) {

  // clear screen
  system("clear");  // for Linux/macOS; use "cls" on Windows if needed

  cout << "=========================\n";
  cout << "Status:\n\n";

  // changing variables
  cout << "Your Health: " << user_health << '\n';
  cout << "Boss Health: " << boss_health << '\n';
  cout << "Turns left: " << (ATTACK_TURN - current_turn) << '\n';
  cout << "Cards left: " << (52 - cards_taken) << '\n';

  // fixed variables
  cout << "Boss Damage: " << BOSS_DAMAGE << "\n\n";

  // Show current hand
  cout << "=== Your Current Hand ===" << endl;
  for (int i = 0; i < player_hand.get_hand_size(); ++i) {
    cout << (i + 1) << ": Rank " << player_hand[i].get_rank()
    << " of Element " << player_hand[i].get_element() << endl;
  }

  cout << "=========================\n\n";
}