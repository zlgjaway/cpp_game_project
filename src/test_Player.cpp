#include "Player.h"
#include "Deck.h"
#include <iostream>

int main() {
    Player player(100, 5);  // Player with 100 HP and hand size 5
    Deck deck;

    std::cout << "[TEST] Drawing cards from an empty deck...\n";
    try {
        player.drawCards(deck);  // Deck not initialized with create()
        std::cout << "[FAIL] No exception thrown when drawing from empty deck.\n";
    } catch (const std::exception& e) {
        std::cout << "[PASS] Exception caught: " << e.what() << "\n";
    }

    std::cout << "[TEST] Applying damage beyond current HP...\n";
    player.takeDamage(150);  // More than current HP
    if (player.getHealth() == 0) {
        std::cout << "[PASS] Player HP correctly clamped to 0.\n";
    } else {
        std::cout << "[FAIL] Player HP is not 0 after overkill damage.\n";
    }

    return 0;
}