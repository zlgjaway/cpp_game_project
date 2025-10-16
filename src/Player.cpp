#include "Player.h"
#include "Deck.h"
#include "Hand.h"
#include "Card.h"


Player::Player(int hp, int maxHand)
    : Character(hp) {
    hand = new Hand(maxHand); // or use default: new Hand()
    std::cout << "[Player] Hand initialized with size " << maxHand << "\n";
}

void Player::drawCards(Deck& deck) {
    if (hand == nullptr) return;
    hand->fillFromDeck(deck);
}

void Player::selectCards(vector<Card> selected) {
    // For now this can be a placeholder; GameController handles selection visually.
    cout << "Player selected " << selected.size() << " cards.\n";
}



void Player::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
    cout << "Player takes " << dmg << " damage. HP now: " << health << endl;
}


Player::~Player() {
    delete hand;
}
