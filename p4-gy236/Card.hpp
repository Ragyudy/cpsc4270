//
// Card.hpp
// Spider-board
//
// Created by Michael Fischer on 9/11/25.
// Modified by Grady Yu on 9/30/25.
//
#ifndef Card_hpp
#define Card_hpp
#include "tools.hpp"
//===============================================================
// This is the main data class; it represents one playing card.
//
class Card {
private:
    // long names for spots and suits
    static constexpr array<const char*, 13> spotLbl = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    static constexpr array<const char*, 4> suitLbl = {"spades", "hearts", "diamonds", "clubs"};
    // single letter names for spots and suits
    static constexpr array<char, 13> spotLetter = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    static constexpr array<char, 4> suitLetter = {'S', 'H', 'D', 'C'};

public:
    // index of last spot or suit
    static constexpr int MAXSPOT = 12;
    static constexpr int MAXSUIT = 3;

private:
    int spot;
    int suit;

public:
    // default ctor with no arguments 
    // (important for instantiating deck)
    Card() noexcept : spot(0), suit(0) {}
    
    // this ctor validates arguments (check Card.cpp)
    Card(int sp, int su);
    string shortName() const;
    string longName() const;
    ostream& print(ostream& out) const;
};

inline ostream& operator<<(ostream& out, Card& cd) {
    return cd.print(out);
}

#endif 
