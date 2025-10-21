#include "Boss.h"

Boss::Boss() {
  boss_health = 1;
  boss_damage = 0;
  boss_turn = 1;
}

Boss::Boss(int boss_damage, int boss_turn, int boss_health) {
  this->boss_damage = boss_damage;
  this->boss_turn = boss_turn;
  this->boss_health = boss_health;
}

// Get User's Card Damage and Lower Boss HP
int Boss::take_damage_boss(int card_damage) {
  boss_health -= card_damage;
}

// Called every turn, checks if turn_counter is 0 (attacks user when it reaches 0)
int Boss::deal_damage_boss() {
  // check if timer is up
  if (boss_counter >= 0) {
    boss_counter = boss_turn;
    return boss_damage;
  }
  boss_counter--; // move timer down;
  return 0;
}



int Boss::get_boss_damage() {
  return boss_damage;
}

int Boss::get_boss_turn() {
  return boss_turn;
}

int Boss::get_boss_health() {
  return boss_health;
}

int Boss::get_boss_counter() {
  return boss_counter;
}

void Boss::set_boss_damage(int boss_damage) {
  this->boss_damage = boss_damage;
}

void Boss::set_boss_turn(int boss_turn) {
  this->boss_turn = boss_turn;
}

void Boss::set_boss_health(int boss_health) {
  this->boss_health = boss_health;
}

void Boss::set_boss_counter(int boss_counter) {
  this->boss_counter = boss_counter;
}