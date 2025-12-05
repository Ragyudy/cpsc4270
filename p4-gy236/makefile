CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -pedantic -g
TARGET = spider

$(TARGET): main.cpp Deck.cpp Card.cpp Pile.cpp Board.cpp Spider.cpp tools.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) 

.PHONY: clean