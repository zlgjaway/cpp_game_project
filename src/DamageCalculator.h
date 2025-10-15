#ifndef DAMAGE_CALCULATOR_H
#define DAMAGE_CALCULATOR_H

#include <vector>
#include <unordered_map>
#include "Card.h"
#include "Hand.h"

int calculate_damage(const Hand& hand, const std::vector<int>& chosen_cards);
int damage_two_cards(const std::vector<int>& ranks);
int damage_three_cards(const std::vector<int>& ranks);
int damage_four_cards(const std::vector<int>& ranks);
int damage_five_cards(const std::vector<int>& ranks, const std::vector<int>& elements);
bool hasFour(const std::unordered_map<int,int>& freq);

#endif

