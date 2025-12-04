//
// runtest driver for pset3
#include "Deck.hpp"
#include "Pile.hpp"
#include "Board.hpp"
#include "tools.hpp"
#include <fstream>
#include <sstream>

int main(int argc, const char* argv[]) {
    banner();
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " scriptfile" << endl;
        return 1;
    }

    ifstream fin(argv[1]);
    if (!fin) {
        cerr << "cannot open script file" << endl;
        return 1;
    }

    string line;
    // first line: seed
    if (!getline(fin, line)) {
        cerr << "empty script" << endl;
        return 1;
    }
    {
        istringstream ss(line);
        int seed = 0;
        ss >> seed;
        srand(seed);
    }

    Deck deck;
    deck.shuffle();
    Board bd(deck);

    while (getline(fin, line)) {
        // skip blanks and comments
        bool allspace = true;
        for (char ch : line) { 
            if (!isspace(static_cast<unsigned char>(ch))) { 
                allspace = false; break; 
            } 
        }
        if (allspace) continue;
        if (!line.empty() && line[0] == '#') continue;

        istringstream ss(line);
        string cmd;
        ss >> cmd;
        cout << "> " << line << endl;
        if (cmd == "moveCards") {
            int n, a, b;
            ss >> n >> a >> b;
            try {
                bd.moveCards(n, bd.pileAt(a - 1), bd.pileAt(b - 1));
            } catch (const exception& e) {
                cerr << e.what() << endl;
            }
        } else if (cmd == "dealRow") {
            try {
                bd.dealRow();
            } catch (const exception& e) {
                cerr << e.what() << endl;
            }
        } else if (cmd == "revealCard") {
            int a; ss >> a;
            try {
                bd.revealCard(bd.pileAt(a - 1));
            } catch (const exception& e) {
                cerr << e.what() << endl;
            }
        } else if (cmd == "removeFullSuit") {
            int a; ss >> a;
            try {
                bd.removeFullSuit(bd.pileAt(a - 1));
            } catch (const exception& e) {
                cerr << e.what() << endl;
            }
        } else if (cmd == "isWon") {
            cout << (bd.isWon() ? "true" : "false") << endl;
        } else if (cmd == "print") {
            bd.print(cout);
        }
    }

    return 0;
}
