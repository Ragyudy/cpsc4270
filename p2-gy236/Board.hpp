//
// Board.hpp
// Spider-board
//
// Created by Grady Yu on 10/23/25.
//

#ifndef Board_hpp
#define Board_hpp

#include "Deck.hpp"
#include "Pile.hpp"
#include <iostream>

using namespace std;

class Board {
private:
    Pile tableau[10];  
    Deck stock;        
    
public:
    Board(Deck& deck);
    void print(ostream& out) const;
};

#endif
