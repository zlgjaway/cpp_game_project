#include <iostream>
#include "Deck.h"
#include "Hand.h"
using namespace std;

int main() {
    // 1. Create and shuffle a deck
    Deck deck;
    deck.create();
    deck.shuffle();
    cout << "Deck created and shuffled.\n";

    // 2. Create a hand and draw 7 cards
    Hand hand;
    cout << "\nDrawing initial hand:\n";
    for (int i = 0; i < 7; ++i) {
        Card c = deck.draw();
        cout << "Card " << i + 1 << ": Rank " << c.get_rank()
             << ", Element " << c.get_element() << endl;
    }

    // 3. Replace chosen cards (simulate user picking 2 cards)
    int chosen_cards[] = {2, 5};
    int chosen_size = 2;
    hand.replace(chosen_cards, chosen_size, deck);
    cout << "\nReplaced cards 2 and 5 with new draws.\n";

    // 4. Sort by rank
    cout << "\nSorting hand by rank:\n";
    hand.sortByRank();

    // 5. Sort by element
    cout << "Sorting hand by element:\n";
    hand.sortByElement();

    cout << "\nAll tests executed successfully.\n";
    return 0;
}
