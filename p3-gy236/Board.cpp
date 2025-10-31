//
// Board.cpp
// Spider-board
//
// Created by Grady Yu on 10/23/25.
//

#include "Board.hpp"
#include <iostream>

using namespace std;

Board::Board(Deck& deck) {
    // deal 44 face-down cards to the tableau
    // first 4 piles get 5 face-down cards each
    for (int pile = 0; pile < 4; pile++) {
        for (int card = 0; card < 5; card++) {
            Card dealtCard = deck.deal();
            tableau[pile].addCard(dealtCard, false);  
        }
    }
    
    // remaining 6 piles get 4 face-down cards each
    for (int pile = 4; pile < 10; pile++) {
        for (int card = 0; card < 4; card++) {
            Card dealtCard = deck.deal();
            tableau[pile].addCard(dealtCard, false);  
        }
    }
    
    // deal 1 face-up card per pile
    for (int pile = 0; pile < 10; pile++) {
        Card dealtCard = deck.deal();
        tableau[pile].addCard(dealtCard, true); 
    }
    
    // store the remaining deck as stock
    stock = deck;
}

void Board::print(ostream& out) const {
    out << "   ";
    for (int col = 1; col <= 10; col++) {
        out << col << "  ";
    }
    out << endl;
    
    // find the maximum number of cards in any pile
    int maxCards = 0;
    for (int pile = 0; pile < 10; pile++) {
        if (tableau[pile].size() > maxCards) {
            maxCards = tableau[pile].size();
        }
    }
    
    for (int row = 0; row < maxCards; row++) {
        out << "   ";
        for (int pile = 0; pile < 10; pile++) {
            string card = tableau[pile].getCardAt(row);
            out << card << " ";
        }
        out << endl;
    }
}
