# Iain Muir
# March 4th, 2020
# Lab Section 102 (11:00 - 12:15 @ OLS 001)

CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -O2
DEBUG = -g

OBJECTS = hashTable.o timer.o wordPuzzle.o

a.out:  $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "HashTable Implementation is fast and ready to rumble!"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
	@echo "Cleaned!"

hashTable.o: hashTable.cpp hashTable.h

timer.o: timer.cpp timer.h

wordPuzzle.o: wordPuzzle.cpp timer.h hashTable.h
