//
// Pile.cpp
// Spider-board
//
// Created by Grady Yu on 10/23/25.
// Modified by Grady Yu on 10/30/25.

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

int Pile::countVisible() const {
    return cardCount - faceDownCount;
}

bool Pile::revealTop() {
    if (cardCount == 0) {
        throw runtime_error("can't reveal top of empty pile");
    }
    if (faceDownCount == cardCount) {
        faceDownCount--;
        return true;
    }
    throw runtime_error("Top card already visible");
}

Pile Pile::removeTopK(int k) {
    if (k < 0) {
        throw runtime_error("can't remove a negative number of cards");
    }
    if (k > countVisible()) {
        throw runtime_error("not enough visible cards to remove");
    }
    Pile result;
    int start = cardCount - k;
    for (int i = start; i < cardCount; i++) {
        result.addCard(cards[i], true);
    }
    cardCount -= k;
    return result;
}

void Pile::pushFromPile(Pile&& other) {
    for (int i = 0; i < other.faceDownCount; i++) {
        addCard(other.cards[i], false);
    }
    
    for (int i = other.faceDownCount; i < other.cardCount; i++) {
        addCard(other.cards[i], true);
    }

    other.cardCount = 0;
    other.faceDownCount = 0;
}
