//
// Card.cpp
// Spider-board
//
// Created by Michael Fischer on 9/11/25.
// Modified by Grady Yu on 9/30/25
//
#include "Card.hpp"
// --------------------------------------------------------------
Card::Card(int sp, int su) : spot(sp), suit(su) {
    if (sp < 0 || sp > MAXSPOT || su < 0 || su > MAXSPOT) {
        throw out_of_range("Bad spot and/or suit");
    }
}

string Card::shortName() const {
    // construct and return a string on the fly
    return {spotLetter[spot], suitLetter[suit]};
}
string Card::longName() const {
    // return string from operator+()
    return string(spotLbl[spot]) + " of " + string(suitLbl[suit]);
}
// --------------------------------------------------------------
ostream& Card::print(ostream& sout) const {
    return sout << longName() << endl;
}
