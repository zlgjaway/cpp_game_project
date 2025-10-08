#ifndef CARD_H
#define CARD_H

class Card {
  protected:
    // 2-14 (J - 11, Q - 12, K - 13, A - 14)
    int rank;
    // (Fire - 1, Water - 2, Earth - 3, Wind - 4)
    int element;
  public:
    Card();
    Card(int rank, int element); 

    int get_rank();
    int get_element();

    void set_rank(int rank);
    void set_element(int element);
};

#endif