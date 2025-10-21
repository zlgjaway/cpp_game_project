#ifndef GAME_LOGGER_H
#define GAME_LOGGER_H

#include <string>

void updateStats(bool won);
void showStats();
void logEvent(const std::string& event);

#endif 