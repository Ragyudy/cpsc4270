CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -pedantic -g
TARGET = main

$(TARGET): main.cpp Deck.cpp Card.cpp Pile.cpp Board.cpp tools.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

.PHONY: clean