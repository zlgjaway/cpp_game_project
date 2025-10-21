#ifndef VIEW_OPTIONS_H
#define VIEW_OPTIONS_H

#include <iostream>
#include <string>
#include <algorithm>
#include "Hand.h"
#include "Boss.h"

#include "display_game_status.h"

void view_options(Hand& player_hand, Hand& player_hand_rank, Hand& player_hand_elem,
                  int user_health, int boss_health, int boss_damage, int boss_turn,
                  int current_turn, int cards_taken);

#endif