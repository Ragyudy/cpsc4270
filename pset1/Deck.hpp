// Deck.cpp
// Spider-board
//
// Created by Grady Yu on 9/30/25.

#include "Card.hpp"

class Deck {
private:
    static constexpr int NUMCARDS = 104; 
    Card cards[NUMCARDS];
    
public:
    Deck();
    void shuffle();
    void print(std::ostream& out) const;
};