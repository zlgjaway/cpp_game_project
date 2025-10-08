#include "Card.h"

Card::Card() {
  rank = 0;
  element = 0;
}

Card::Card(int rank, int element) {
  this->rank = rank;
  this->element = element;
}

int Card::get_rank() {
  return rank;
}

int Card::get_element() {
  return element;
}

void Card::set_rank(int rank) {
  this->rank = rank;
}

void Card::set_element(int element) {
  this->element = element;
}