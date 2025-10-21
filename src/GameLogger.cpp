#include "GameLogger.h"
#include <fstream>
#include <iostream>

void updateStats(bool won) {
    int wins = 0, losses = 0;

    std::ifstream inFile("stats.txt");
    if (inFile.is_open()) {
        inFile >> wins >> losses;
        inFile.close();
    }

    if (won) wins++;
    else losses++;

    std::ofstream outFile("stats.txt");
    outFile << wins << " " << losses;
    outFile.close();
}

void showStats() {
    int wins = 0, losses = 0;
    std::ifstream inFile("stats.txt");
    if (inFile.is_open()) {
        inFile >> wins >> losses;
        inFile.close();
    }
    std::cout << "Wins: " << wins << ", Losses: " << losses << "\n";
}

void logEvent(const std::string& event) {
    std::ofstream logFile("game_log.txt", std::ios::app);
    logFile << event << "\n";
    logFile.close();
}