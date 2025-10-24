//
// cardtest unit test
//
// Created by Michael Fischer on 9/15/25.
//
// This is a unit test of the Card class constructor
// and its public shortName() function.
// It does not test the longName() function.
// It creates a specified number of decks of cards
// and write the result to an output file.
//
// Usage: cardtest num_decks outfile
#include "Deck.hpp"
#include "Pile.hpp"
#include "Board.hpp"
#include "tools.hpp"
// --------------------------------------------------------------
int main(int argc, const char* argv[]) {
    banner();
    // Process command line arg
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " seed" << endl;
        return 1;
    }

    int seed = atoi(argv[1]);
    srand(seed);
    Deck deck;
    deck.shuffle();
    
    cout << "Spider Board:" << endl;
    Board board(deck);
    board.print(cout);
    
    bye();
    return 0;
}
