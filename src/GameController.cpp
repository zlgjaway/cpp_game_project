#include "GameController.h"
#include <algorithm>
#include <iostream>
#include <functional>
#include "GameLogger.h"

GameController::GameController()
    : window(sf::VideoMode(1000, 600), "SFML Card Battle"),
      turnCounter(0),
      gameOver(false) {}
// move card
void GameController::repositionHand() {
    int x = 60, y = 380;
    for (int i = 0; i < player.getHand().getSize(); ++i) {
        player.getHand().get_card(i).setPosition(x, y);
        x += 130;
    }
}

// sort by element
void GameController::onSortElement() { 
    std::cout << "[UI] Sort by Element\n";
    player.getHand().logHand("Before Element Sort");
    player.getHand().sortByElement();
    player.getHand().logHand("After Element Sort");
    repositionHand();
}

// sort by rank
void GameController::onSortRank() {  
    std::cout << "[UI] Sort by Rank\n";
    player.getHand().logHand("Before Rank Sort");
    player.getHand().sortByRank();
    player.getHand().logHand("After Rank Sort");
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
// game loop start
void GameController::startGame() {
    
    
    std::cout << "Welcome to the Card Battle Game!\n";
    showStats();

    // Show game menu to select boss
    GameMenu menu(window);
    int bossChoice = menu.show();
    if (bossChoice == -1) return;

    // Clean up previous boss if any
    if (boss) {
        delete boss;
        boss = nullptr;
    }

    // Create new boss based on choice
    switch (bossChoice) {
        case 1: boss = new Orge(); break;
        case 2: boss = new Phoenix(); break;
        case 3: boss = new Leviathan(); break;
        default: boss = new Orge(); break;
    }
    // create button 
    initUI();

    deck.create();
    std::cout << "[GameController] Deck created.\n";

    std::cout << "[GameController] Shuffling deck...\n";
    deck.shuffle();
    std::cout << "[GameController] Deck shuffled.\n";

    boss->create();
    std::cout << "[GameController] Filling player's hand...\n";
    player.getHand().fillFromDeck(deck);
    std::cout << "[GameController] Hand filled.\n";

    repositionHand();
    // mouse control
    while (window.isOpen() && !gameOver) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {

                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                if (btnSortElement.box.getGlobalBounds().contains(mousePos)) {
                    btnSortElement.onClick();
                }
                if (btnSortRank.box.getGlobalBounds().contains(mousePos)) {
                    btnSortRank.onClick();
                }
                if (btnPlay.box.getGlobalBounds().contains(mousePos)) {
                    btnPlay.onClick();
                }

                int selectedCount = 0;
                for (int i = 0; i < player.getHand().getSize(); ++i) {
                    if (player.getHand().get_card(i).selected) {
                        selectedCount++;
                    }
                }

                for (int i = 0; i < player.getHand().getSize(); ++i) {
                    auto& card = player.getHand().get_card(i);
                    if (card.getSprite().getGlobalBounds().contains(mousePos)) {
                        if (!card.selected && selectedCount < 5) {
                            card.selected = true;
                            card.setPosition(card.getPosition().x, card.getPosition().y - 30);
                        } else if (card.selected) {
                            card.selected = false;
                            card.setPosition(card.getPosition().x, card.getPosition().y + 30);
                        }
                        break;
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Enter) {
                playerTurn();
                if (!gameOver) {
                    bossTurn();
                    checkVictoryConditions();
                }
            }
        }

        window.clear(sf::Color(25, 25, 112)); // Midnight Blue

        for (int i = 0; i < player.getHand().getSize(); ++i) {
            window.draw(player.getHand().get_card(i).getSprite());
        }

        window.draw(boss->getSprite());

        btnSortElement.draw(window);
        btnSortRank.draw(window);
        btnPlay.draw(window);
        // adding heath point 
        sf::Text bossHealthText;
        bossHealthText.setFont(uiFont);
        bossHealthText.setCharacterSize(24);
        bossHealthText.setFillColor(sf::Color::Red);
        bossHealthText.setPosition(20, 20);
        bossHealthText.setString("Boss HP: " + std::to_string(boss->getHealth()));
        
        sf::Text playerHealthText;
        playerHealthText.setFont(uiFont);
        playerHealthText.setCharacterSize(24);
        playerHealthText.setFillColor(sf::Color::White);
        playerHealthText.setPosition(20, 50);
        playerHealthText.setString("Player HP: " + std::to_string(player.getHealth()));

        window.draw(bossHealthText);
        window.draw(playerHealthText);

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

    if (selectedIndices.size() > 5) {
        std::cout << "[Turn] You can only select up to 5 cards!\n";
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

    int damage = calculate_damage(player.getHand(), selectedIndices);
    boss->takeDamage(damage);

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
    boss->deal_boss_damage(player);
}

void GameController::checkVictoryConditions() {
    if (boss->getHealth() <= 0) {
        std::cout << "You win!\n";
        logEvent("Player defeated the boss.");
        updateStats(true);
        gameOver = true;
    } else if (player.getHealth() <= 0) {
        std::cout << "You lose!\n";
        logEvent("Player was defeated by the boss.");
        updateStats(false);
        gameOver = true;
    }
}

void GameController::updateButtonLayout() {
    const float W = static_cast<float>(window.getSize().x);
    const float H = static_cast<float>(window.getSize().y);

    const sf::Vector2f size{180.f, 40.f};
    const float margin = 16.f;

    sf::Vector2f posElement{margin, H - size.y - margin};
    sf::Vector2f posRank{posElement.x + size.x + margin, posElement.y};
    sf::Vector2f posPlay{W - size.x - margin, H - size.y - margin};

    btnSortElement.setup(uiFont, "Sort by Element", posElement, size);
    btnSortRank.setup(uiFont, "Sort by Rank", posRank, size);
    btnPlay.setup(uiFont, "Play Selected", posPlay, size);
}

void GameController::initUI() {
    if (!uiFont.loadFromFile("../assets/fonts/Roboto-Regular.ttf")) {
        std::cerr << "[UI] Failed to load font at assets/fonts/Roboto-Regular.ttf\n";
    }

    updateButtonLayout();
    // button function
    btnSortElement.onClick = std::bind(&GameController::onSortElement, this);
    btnSortRank.onClick = std::bind(&GameController::onSortRank, this);
    btnPlay.onClick = std::bind(&GameController::onPlayClicked, this);

    btnSortElement.box.setFillColor(sf::Color(70, 130, 180));
    btnSortRank.box.setFillColor(sf::Color(46, 139, 87));
    btnPlay.box.setFillColor(sf::Color(218, 165, 32));
}

GameController::~GameController() {
    delete boss;
    boss = nullptr;
}
