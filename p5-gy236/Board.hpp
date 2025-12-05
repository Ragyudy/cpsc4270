//
// Board.hpp
// Spider-board
//
// Created by Grady Yu on 10/23/25.
// Modified by Grady Yu on 10/30/25.

#ifndef Board_hpp
#define Board_hpp

#include "Deck.hpp"
#include "Pile.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Board {
private:
    Pile stk[10];  
    Deck stock;        
    vector<Pile> foundation; 
    
public:
    Board(Deck& deck);
    void print(ostream& out) const;
    void moveCards(int k, Pile& source, Pile& target);
    void dealRow();
    void revealCard(Pile& pile);
    void removeFullSuit(Pile& pile);
    bool isWon() const;
    Pile& pileAt(int idx) { return stk[idx]; }
    const Pile& pileAt(int idx) const { return stk[idx]; }
    
    void turnOverCards();
    void removeCompletedSuits();
};

#endif
