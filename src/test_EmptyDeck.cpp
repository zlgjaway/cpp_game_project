#include <iostream>
#include "Deck.h"

int main() {
    Deck deck;

    // Do not call deck.create() to simulate an empty deck
    try {
        for (int i = 0; i < 53; ++i) {  // Try drawing one more than the deck size
            Card card = deck.draw();
            std::cout << "Drawn card " << i + 1 << "\n";
        }
        std::cout << "[FAIL] No exception thrown when drawing from empty deck.\n";
    } catch (const std::runtime_error& e) {
        std::cout << "[PASS] Exception caught: " << e.what() << "\n";
    } catch (...) {
        std::cout << "[FAIL] Unexpected exception type caught.\n";
    }

    return 0;
}