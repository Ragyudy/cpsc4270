//
// Pile.hpp
// Spider-board
//
// Created by Grady Yu on 10/23/25.
// Modified by Grady Yu on 10/30/25.

#ifndef Pile_hpp
#define Pile_hpp

#include "Card.hpp"
#include <iostream>

using namespace std;

class Pile {
private:
    static constexpr int MAX_CARDS = 20;  
    Card cards[MAX_CARDS];                
    int cardCount;                        
    int faceDownCount;                    
    
public:
    Pile();
    void addCard(const Card& card, bool faceUp = true);
    void print(ostream& out) const;
    int size() const;
    bool isEmpty() const;
    string getCardAt(int position) const; 
    int countVisible() const;
    bool revealTop();
    Pile removeTopK(int k);
    void pushFromPile(Pile&& other);
};

#endif 
