#include <iostream>
#include "Deck.h"
#include "Hand.h"
#include "DamageCalculator.h"
using namespace std;

int main() {
    Deck deck;
    deck.create();
    deck.shuffle();

    Hand player_hand(7);

    cout << "Drawing hand:\n";
    for (int i = 0; i < 7; i++) {
        player_hand.set_card(i, deck.draw());
        cout << i + 1 << ". Rank: " << player_hand.get_card(i).get_rank()
             << ", Element: " << player_hand.get_card(i).get_element() << endl;
    }

    int chosen[] = {1, 2, 3, 4, 5};
    int damage = dmg_calc(chosen, 5, player_hand);
    cout << "Total Damage: " << damage << endl;

    return 0;
}