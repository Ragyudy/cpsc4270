//
// Deck.hpp
// Spider-board
//
// Created by Grady Yu on 9/30/25. Modified by Grady Yu on 10/23/25
//

#ifndef Deck_hpp
#define Deck_hpp

#include "Card.hpp"
#include <iostream>

using namespace std;

class Deck {
private:
    static constexpr int NUMCARDS = 104; 
    Card cards[NUMCARDS];
    int top; 
    
public:
    Deck();
    void shuffle();
    void print(ostream& out) const;
    Card deal(); 
};

#endif