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
#include "Card.hpp"
#include "tools.hpp"
// --------------------------------------------------------------
int main(int argc, const char* argv[]) {
banner();
// Process command line args
if (argc != 3) {
cerr << "Usage: cardtest num_decks outfile" << endl;
return 1;
}
int numDecks = atoi(argv[1]);
// Sanity check
if (numDecks < 1 || numDecks > 10)
fatal("num_decks not in reasonable range [1,10]");
string outfile = string(argv[2]);
// Open output file
ofstream os(outfile);
if (!os.is_open())
fatal("Can't open file " + outfile + " for writing");
// Main test loop
for (int count = 0; count < numDecks; count++) {
for (int spot = 1; spot <= Card::MAXSPOT; spot++) {
for (int suit = 1; suit <= Card::MAXSUIT; suit++) {
Card cd(spot, suit);
os << cd.shortName() << " ";
}
os << endl;
}
}
// Close output file
os.close();
bye();
return 0;
}
