#include "GameController.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <functional>
#include "Button.h"
#include <functional>


GameController::GameController()
    : window(sf::VideoMode(1000, 600), "SFML Card Battle"),
      turnCounter(0),
      gameOver(false) {}

void GameController::repositionHand() {
    int x = 60, y = 380; // baseline row
    for (int i = 0; i < player.getHand().getSize(); ++i) {
        player.getHand().get_card(i).setPosition(x, y);
        x += 130;
    }
}
void GameController::onSortElement() {
        std::cout << "[UI] Sort by Element\n";
        player.getHand().sortByElement();
        repositionHand();
}

void GameController::onSortRank() {
        std::cout << "[UI] Sort by Rank\n";
        player.getHand().sortByRank();
        repositionHand();
}

void GameController::onPlayClicked() {
        std::cout << "[UI] Play Selected\n";
        playerTurn();
        checkVictoryConditions();
        if (!gameOver) {
            bossTurn();
            checkVictoryConditions();
        }
}

void GameController::startGame() {
    initUI();  //set up UI buttons


    deck.create();
    std::cout << "[GameController] Deck created.\n";

    std::cout << "[GameController] Shuffling deck...\n";
    deck.shuffle();
    std::cout << "[GameController] Deck shuffled.\n";
    boss.create(); // Load boss sprite
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
                
                
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                // Check if any button was clicked
                if (btnSortElement.box.getGlobalBounds().contains(mousePos)) {
                        btnSortElement.onClick();
                }
                if (btnSortRank.box.getGlobalBounds().contains(mousePos)) {
                        btnSortRank.onClick();
                }
                if (btnPlay.box.getGlobalBounds().contains(mousePos)) {
                        btnPlay.onClick();
                }


                //const auto mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                for (int i = 0; i < player.getHand().getSize(); ++i) {
                    auto& card = player.getHand().get_card(i);
                    if (card.getSprite().getGlobalBounds().contains(mousePos)) {
                        card.selected = !card.selected;
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

        // Draw the boss
        window.draw(boss.getSprite());
        
        // Draw UI on top
        btnSortElement.draw(window);
        btnSortRank.draw(window);
        btnPlay.draw(window);

        window.display();

        if (gameOver) {
            sf::sleep(sf::milliseconds(600));
            window.close();
        }
    }
}

void GameController::playerTurn() {
    std::vector<int> selectedIndices;

    for (int i = 0; i < player.getHand().getSize(); ++i) {
        auto& card = player.getHand().get_card(i);
        if (card.selected) {
            selectedIndices.push_back(i);
            card.selected = false;
        }
    }

    if (selectedIndices.empty()) {
        std::cout << "[Turn] No cards selected. Select cards then press Enter.\n";
        return;
    }

    std::sort(selectedIndices.begin(), selectedIndices.end());
    selectedIndices.erase(std::unique(selectedIndices.begin(), selectedIndices.end()), selectedIndices.end());

    const int handSize = player.getHand().getSize();
    for (int idx : selectedIndices) {
        if (idx < 0 || idx >= handSize) {
            std::cerr << "ERROR: Selected index out of range: " << idx
                      << " (hand size=" << handSize << ")\n";
            gameOver = true;
            return;
        }
    }

    ++turnCounter;
    std::cout << "\n[Turn " << turnCounter << "] Player played "
              << selectedIndices.size() << " card(s).\n";
    boss.takeDamage(static_cast<int>(selectedIndices.size()) * 10);

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

    repositionHand();
}

void GameController::bossTurn() {
    boss.deal_boss_damage(player); // Use Orge's custom attack
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


void GameController::updateButtonLayout() {
    const float W = static_cast<float>(window.getSize().x);
    const float H = static_cast<float>(window.getSize().y);

    // Use compact UI button size
    const sf::Vector2f size{180.f, 40.f};
    const float margin = 16.f;

    // Bottom-left, bottom-middle, bottom-right
    sf::Vector2f posElement{margin, H - size.y - margin};
    sf::Vector2f posRank{posElement.x + size.x + margin, posElement.y};
    sf::Vector2f posPlay{W - size.x - margin, H - size.y - margin};

    btnSortElement.setup(uiFont, "Sort by Element", posElement, size);
    btnSortRank.setup(uiFont,    "Sort by Rank",    posRank,    size);
    btnPlay.setup(uiFont,        "Play Selected",   posPlay,    size);

}


void GameController::initUI() {
    if (!uiFont.loadFromFile("../assets/fonts/Roboto-Regular.ttf")) {
        std::cerr << "[UI] Failed to load font at assets/fonts/Roboto-Regular.ttf\n";
    }

    updateButtonLayout();

    // Bind member functions to the button onClick handlers (C++11)
    btnSortElement.onClick = std::bind(&GameController::onSortElement, this);
    btnSortRank.onClick    = std::bind(&GameController::onSortRank, this);
    btnPlay.onClick        = std::bind(&GameController::onPlayClicked, this);

    
    // After setup() in initUI() or updateButtonLayout():
    btnSortElement.box.setFillColor(sf::Color(70, 130, 180)); // SteelBlue
    btnSortRank.box.setFillColor(sf::Color(46, 139, 87));     // SeaGreen
    btnPlay.box.setFillColor(sf::Color(218, 165, 32));        // Goldenrod

}

