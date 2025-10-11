#include <iostream>
#include "Deck.h"
#include "Hand.h"
using namespace std;

int main() {
    Deck deck;
    deck.create();
    deck.shuffle();
    cout << "Deck created and shuffled.\n";

    Hand hand;
    hand.fillFromDeck(deck);

    cout << "\nInitial hand:\n";
    for (int i = 0; i < 7; ++i)
        cout << "Card " << i + 1 << ": Rank " << hand.get_card(i).get_rank()
             << ", Element " << hand.get_card(i).get_element() << endl;

    // simulate replacement of cards 2 and 5
    int chosen_cards[] = {2, 5};
    int chosen_size = 2;
    hand.replace(chosen_cards, chosen_size, deck);

    cout << "\nAfter replacement:\n";
    for (int i = 0; i < 7; ++i)
        cout << "Card " << i + 1 << ": Rank " << hand.get_card(i).get_rank()
             << ", Element " << hand.get_card(i).get_element() << endl;

    cout << "\nSorting by rank:\n";
    hand.sortByRank();
    for (int i = 0; i < 7; ++i)
        cout << "Card " << i + 1 << ": Rank " << hand.get_card(i).get_rank()
             << ", Element " << hand.get_card(i).get_element() << endl;

    cout << "\nSorting by element:\n";
    hand.sortByElement();
    for (int i = 0; i < 7; ++i)
        cout << "Card " << i + 1 << ": Rank " << hand.get_card(i).get_rank()
             << ", Element " << hand.get_card(i).get_element() << endl;

    cout << "\nAll tests completed.\n";
    return 0;
}
