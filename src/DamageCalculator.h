#ifndef DAMAGE_CALCULATOR_H
#define DAMAGE_CALCULATOR_H

#include <iostream>
#include "Card.h"
#include "Hand.h"

int dmg_calc(int* chosen_indices, int chosen_size, Hand& player_hand);

int scenario_5cards(Card* chosen_cards, int chosen_size);
int scenario_4cards(Card* chosen_cards, int chosen_size);
int scenario_3cards(Card* chosen_cards, int chosen_size);
int scenario_2cards(Card* chosen_cards, int chosen_size);

#endif

