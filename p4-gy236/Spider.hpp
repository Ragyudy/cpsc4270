//
// Spider.hpp
// Spider Solitaire Controller
// Created by Grady Yu on 11/30/25.
//

#ifndef Spider_hpp
#define Spider_hpp

#include "Board.hpp"
#include "Deck.hpp"
#include <iostream>

using namespace std;

class Spider {
private:
    const int seed;        
    Board* board;           
    
    // helper methods for each action (B, D, M, Q)
    void handleBegin();    
    void handleDeal();     
    void handleMove(istream& in); 
    void handleQuit();     
    
    // input validation helpers
    bool isValidCommand(char cmd) const;
    bool isValidPileNumber(int pileNum) const;
    bool isValidCardCount(int k) const;
    
public:
    Spider(int seed);     
    ~Spider();
    void play();           
};

#endif 

