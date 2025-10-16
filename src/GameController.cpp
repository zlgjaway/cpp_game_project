#include "GameController.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

GameController::GameController()
    : window(sf::VideoMode(1000, 600), "SFML Card Battle"),
      turnCounter(0),
      gameOver(false) {}

void GameController::repositionHand() {
    int x = 60, y = 420; // baseline row
    for (int i = 0; i < player.getHand().getSize(); ++i) {
        player.getHand().get_card(i).setPosition(x, y);
        x += 130;
    }
}

void GameController::startGame() {
    // Build deck & initial hand
    
    deck.create();
    std::cout << "[GameController] Deck created.\n";

    std::cout << "[GameController] Shuffling deck...\n";
    deck.shuffle();
    std::cout << "[GameController] Deck shuffled.\n";

    std::cout << "[GameController] Filling player's hand...\n";
    player.getHand().fillFromDeck(deck);
    std::cout << "[GameController] Hand filled.\n";

    std::cout << "[GameController] Repositioning hand...\n";
    repositionHand();
    std::cout << "[GameController] Hand repositioned.\n";


    // Main loop
    while (window.isOpen() && !gameOver) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Mouse click: select/deselect cards
            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {

                // Use SFML mapping (works with views/zoom)
                const auto mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                for (int i = 0; i < player.getHand().getSize(); ++i) {
                    auto& card = player.getHand().get_card(i);
                    if (card.getSprite().getGlobalBounds().contains(mousePos)) {
                        card.selected = !card.selected;
                        // Simple visual feedback: lift/drop by 30 px
                        if (card.selected) {
                            card.setPosition(card.getPosition().x, card.getPosition().y - 30);
                        } else {
                            card.setPosition(card.getPosition().x, card.getPosition().y + 30);
                        }
                    }
                }
            }

            // Enter key: confirm selection and resolve turn
            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Enter) {

                playerTurn();

                if (!gameOver) {
                    bossTurn();
                    checkVictoryConditions();
                }
            }
        }

        // Draw scene
        window.clear(sf::Color(0, 150, 0)); // green table

        // Draw all player's cards
        for (int i = 0; i < player.getHand().getSize(); ++i) {
            window.draw(player.getHand().get_card(i).getSprite());
        }

        window.display();

        // If game ended during drawing, close gracefully after a short delay
        if (gameOver) {
            sf::sleep(sf::milliseconds(600));
            window.close();
        }
    }
}

void GameController::playerTurn() {
    std::vector<int> selectedIndices;

    // Collect selected cards (0-based indice)
    for (int i = 0; i < player.getHand().getSize(); ++i) {
        auto& card = player.getHand().get_card(i);
        if (card.selected) {
            selectedIndices.push_back(i);
            card.selected = false; // clear selection flag
        }
    }

    if (selectedIndices.empty()) {
        std::cout << "[Turn] No cards selected. Select cards then press Enter.\n";
        return;
    }

    // De-dup and sort (defensive)
    std::sort(selectedIndices.begin(), selectedIndices.end());
    selectedIndices.erase(std::unique(selectedIndices.begin(),
                                      selectedIndices.end()),
                          selectedIndices.end());

    // Validate indices
    const int handSize = player.getHand().getSize();
    for (int idx : selectedIndices) {
        if (idx < 0 || idx >= handSize) {
            std::cerr << "ERROR: Selected index out of range: " << idx
                      << " (hand size=" << handSize << ")\n";
            gameOver = true; // bail to avoid UB
            return;
        }
    }

    // Simple damage rule
    ++turnCounter;
    std::cout << "\n[Turn " << turnCounter << "] Player played "
              << selectedIndices.size() << " card(s).\n";
    boss.takeDamage(static_cast<int>(selectedIndices.size()) * 10);

    // Replace selected cards from deck
    try {
        player.getHand().replace(selectedIndices.data(),
                                 static_cast<int>(selectedIndices.size()),
                                 deck);
    } catch (const std::exception& ex) {
        std::cerr << "ERROR: Hand::replace threw: " << ex.what() << "\n";
        gameOver = true;
        return;
    } catch (...) {
        std::cerr << "ERROR: Hand::replace threw (unknown).\n";
        gameOver = true;
        return;
    }

    // Reposition current hand row
    repositionHand();
}

void GameController::bossTurn() {
    const int damage = 10;
    std::cout << "Boss attacks for " << damage << " damage!\n";
    player.takeDamage(damage);
}

void GameController::checkVictoryConditions() {
    if (boss.getHealth() <= 0) {
        std::cout << "You win!\n";
        gameOver = true;
    } else if (player.getHealth() <= 0) {
        std::cout << "You lose!\n";
        gameOver = true;
    }
}