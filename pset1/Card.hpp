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
    static constexpr const char* spotLbl[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    static constexpr const char* suitLbl[13] = {"spades", "hearts", "diamonds", "clubs"};
    // single letter names for spots and suits
    static constexpr const char* spotLetter = "A23456789TJQK";
    static constexpr const char* suitLetter = "SHDC";

public:
    // index of last spot or suit
    static constexpr int MAXSPOT = 12;
    static constexpr int MAXSUIT = 3;

private:
    int spot;
    int suit;

public:
    Card(int sp, int su) : spot(sp), suit(su) {}
    string shortName() const;
    string longName() const;
    ostream& print(ostream& out) const;
};

inline ostream& operator<<(ostream& out, Card& cd) {
    return cd.print(out);
}

#endif /* Card_hpp */
