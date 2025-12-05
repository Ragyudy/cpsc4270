//
// Spider.cpp
// Spider Solitaire Controller
// Created by Grady Yu on 11/30/25.
//

#include "Spider.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>

using namespace std;

Spider::Spider(int seed) : seed(seed), board(nullptr) {
    Deck deck;
    deck.shuffle();
    board = new Board(deck);
    board->print(cout);
}

Spider::~Spider() {
    delete board;
}

void Spider::play() {
    string line;
    
    while (getline(cin, line)) {
        if (line.empty()) continue;
        
        istringstream iss(line);
        char cmd;
        iss >> cmd;
        
        cmd = toupper(static_cast<unsigned char>(cmd));
        
        if (!isValidCommand(cmd)) {
            cerr << "Invalid command: " << cmd << endl;
            continue;
        }
        
        try {
            switch (cmd) {
                case 'B':
                    handleBegin();
                    break;
                case 'D':
                    handleDeal();
                    break;
                case 'M':
                    handleMove(iss);
                    break;
                case 'Q':
                    handleQuit();
                    break;
            }
        } catch (const exception& e) {
            if (cmd == 'Q') {
                return;  
            }
            if (cmd != 'B') {
                cerr << e.what() << endl;
            }
        }
    }
}

void Spider::handleBegin() {
    delete board;
    Deck deck;
    deck.shuffle();
    board = new Board(deck);
    board->print(cout);
    throw runtime_error("New game started");
}

void Spider::handleDeal() {
    board->dealRow();
    board->print(cout);
    
    if (board->isWon()) {
        cout << "Yay, you won!!!" << endl;
        throw runtime_error("Game won");
    }
}

void Spider::handleMove(istream& in) {
    int a, b, k;
    
    if (!(in >> a >> b >> k)) {
        throw runtime_error("Invalid move command: expected M a b k");
    }
    
    if (!isValidPileNumber(a) || !isValidPileNumber(b)) {
        throw runtime_error("Pile numbers must be between 1 and 10");
    }
    
    if (!isValidCardCount(k)) {
        throw runtime_error("Number of cards must be between 1 and 13");
    }
    
    Pile& source = board->pileAt(a - 1);
    Pile& target = board->pileAt(b - 1);
    
    board->moveCards(k, source, target);
    board->print(cout);
    
    if (board->isWon()) {
        cout << "Yay, you won!!!" << endl;
        throw runtime_error("Game won");
    }
}

void Spider::handleQuit() {
    cout << "Game quit." << endl;
    throw runtime_error("Game quit");
}

bool Spider::isValidCommand(char cmd) const {
    return cmd == 'B' || cmd == 'D' || cmd == 'M' || cmd == 'Q';
}

bool Spider::isValidPileNumber(int pileNum) const {
    return pileNum >= 1 && pileNum <= 10;
}

bool Spider::isValidCardCount(int k) const {
    return k >= 1 && k <= 13;
}

