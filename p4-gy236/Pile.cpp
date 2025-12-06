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
    throw runtime_error("top card already visible");
}

Pile Pile::removeTopK(int k) {
    if (k <= 0) throw runtime_error("can't remove zero or negative number of cards");
    if (k > countVisible()) throw runtime_error("not enough visible cards to remove");
    
    Pile result;
    int start = cardCount - k;
    for (int i = start; i < cardCount; i++) {
        result.addCard(cards[i], true);
    }
    cardCount -= k;
    
    if (cardCount > 0 && faceDownCount > 0 && faceDownCount == cardCount) {
        faceDownCount--;
    }
    
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

Card Pile::getTopCard() const {
    if (cardCount == 0) {
        throw runtime_error("can't get top card of empty pile");
    }
    if (faceDownCount == cardCount) {
        throw runtime_error("top card is hidden");
    }
    return cards[cardCount - 1];
}

bool Pile::isRun(int k) const {
    if (k <= 0 || k > countVisible()) return false;
    if (k == 1) return true;  
    
    int start = cardCount - k;
    int firstSuit = cards[start].getSuit();
    
    for (int i = start; i < cardCount - 1; i++) {
        int currentSpot = cards[i].getSpot();
        int nextSpot = cards[i + 1].getSpot();        
        if (nextSpot != currentSpot - 1) return false;
    }
    
    for (int i = start + 1; i < cardCount; i++) {
        if (cards[i].getSuit() != firstSuit) return false;
    }
    
    return true;
}

Card Pile::getBottomOfRun(int k) const {
    if (!isRun(k)) throw runtime_error("top k cards do not form a run");
    int start = cardCount - k;
    return cards[start];
}

bool Pile::canAcceptRun(const Card& bottomCard) const {
    if (cardCount == 0) return true;
    Card topCard = getTopCard();
    return topCard.getSpot() == bottomCard.getSpot() + 1;
}
