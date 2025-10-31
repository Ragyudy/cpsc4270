//
// Pile.cpp
// Spider-board
//
// Created by Grady Yu on 10/23/25.
//

#include "Pile.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

Pile::Pile() : cardCount(0), faceDownCount(0) {}

void Pile::addCard(const Card& card, bool faceUp) {
    if (cardCount >= MAX_CARDS) {
        throw runtime_error("Pile is full");
    }
    cards[cardCount] = card;
    cardCount++;
    if (!faceUp) {
        faceDownCount++;
    }
}

void Pile::print(ostream& out) const {
    if (cardCount == 0) {
        out << "--";
        return;
    }
    
    for (int i = 0; i < faceDownCount; i++) {
        out << "--";
        if (i < faceDownCount - 1) out << " ";
    }
    
    for (int i = faceDownCount; i < cardCount; i++) {
        if (i > 0) out << " "; 
        out << cards[i].shortName();
    }
}

int Pile::size() const {
    return cardCount;
}

bool Pile::isEmpty() const {
    return cardCount == 0;
}

string Pile::getCardAt(int position) const {
    if (position < 0 || position >= cardCount) {
        return "  "; 
    }
    
    if (position < faceDownCount) {
        return "--"; 
    } else {
        return cards[position].shortName();  
    }
}
