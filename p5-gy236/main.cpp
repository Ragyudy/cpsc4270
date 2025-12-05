//
// main.cpp
//
#include "Spider.hpp"
#include "tools.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, const char* argv[]) {
    banner();
    
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <seed>" << endl;
        return 1;
    }
    
    int seed = atoi(argv[1]);
    srand(seed);
    
    Spider game(seed);
    game.play();
    
    bye();
    return 0;
}
