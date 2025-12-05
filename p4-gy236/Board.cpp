//
// Board.cpp
// Spider-board
//
// Created by Grady Yu on 10/23/25. 
// Modified by Grady Yu on 10/30/25

#include "Board.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

Board::Board(Deck& deck) {
    // deal 44 face-down cards to the tableau
    // first 4 piles get 5 face-down cards each
    for (int pile = 0; pile < 4; pile++) {
        for (int card = 0; card < 5; card++) {
            Card dealtCard = deck.deal();
            stk[pile].addCard(dealtCard, false);  
        }
    }
    
    // remaining 6 piles get 4 face-down cards each
    for (int pile = 4; pile < 10; pile++) {
        for (int card = 0; card < 4; card++) {
            Card dealtCard = deck.deal();
            stk[pile].addCard(dealtCard, false);  
        }
    }
    
    // deal 1 face-up card per pile
    for (int pile = 0; pile < 10; pile++) {
        Card dealtCard = deck.deal();
        stk[pile].addCard(dealtCard, true); 
    }
    
    // store the remaining deck as stock
    stock = deck;
}

void Board::moveCards(int k, Pile& source, Pile& target) {
    if (k <= 0) throw runtime_error("cannot move zero or negative number of cards");
    if (source.countVisible() < k) throw runtime_error("source pile has less than k visible cards");
    Pile moved = source.removeTopK(k);
    target.pushFromPile(std::move(moved));
}

void Board::dealRow() {
    if (stock.remaining() < 10) throw runtime_error("stock has less than 10 cards");
    for (int i = 0; i < 10; i++) {
        Card c = stock.deal();
        stk[i].addCard(c, true);
    }
}

void Board::revealCard(Pile& pile) {
    pile.revealTop();
}

void Board::removeFullSuit(Pile& pile) {
    const int SUIT_LEN = 13;
    if (pile.countVisible() < SUIT_LEN) throw runtime_error("pile has less than 13 visible cards");
    Pile suit = pile.removeTopK(SUIT_LEN);
    foundation.push_back(Pile());
    // std::move is used to move the suit pile to the foundation
    foundation.back().pushFromPile(std::move(suit));
}

bool Board::isWon() const {
    int total = 0;
    for (const auto& p : foundation) {
        total += p.size();
    }
    return total == 104;
}

void Board::print(ostream& out) const {
    // print foundation first if not empty
    if (!foundation.empty()) {
        out << "Foundation: ";
        for (size_t i = 0; i < foundation.size(); i++) {
            out << "[";
            foundation[i].print(out);
            out << "]";
            if (i + 1 < foundation.size()) out << " ";
        }
        out << endl;
    }

    out << "   ";
    for (int col = 1; col <= 10; col++) {
        out << col << "  ";
    }
    out << endl;
    
    // find the maximum number of cards in any pile
    int maxCards = 0;
    for (int pile = 0; pile < 10; pile++) {
        if (stk[pile].size() > maxCards) {
            maxCards = stk[pile].size();
        }
    }
    
    for (int row = 0; row < maxCards; row++) {
        out << "   ";
        for (int pile = 0; pile < 10; pile++) {
            string card = stk[pile].getCardAt(row);
            out << card << " ";
        }
        out << endl;
    }
}
