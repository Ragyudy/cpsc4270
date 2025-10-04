// Deck.cpp
// Spider-board
//
// Created by Grady Yu on 9/30/25.

#include "Card.hpp"
#include "Deck.hpp"
#include <cstdlib>

Deck::Deck() {
    int idx = 0;
    for (int k = 0; k < 2; k++) {
        for (int su = 0; su <= Card::MAXSUIT; su++) {
            for (int sp = 0; sp <= Card::MAXSPOT; sp++) {
                cards[idx++] = Card(sp, su);
            }
        }
    }
}

void Deck::shuffle() {
    // randomly swap cards until there are only one card left
    for (int k = NUMCARDS; k > 1; k--) {
        int random_card = rand() % k;
        swap(cards[random_card], cards[k - 1]);
    }
}

void Deck::print(std::ostream& out) const {
    for (int k = 0; k < NUMCARDS; k++) {
        out << cards[k].shortName() << " ";
        if ((k + 1) % 13 == 0) out << endl;
    }
}