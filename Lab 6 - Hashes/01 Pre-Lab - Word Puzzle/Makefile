# Iain Muir, iam9ez
# March 2nd, 2020
# Lab Section 102 (11:00 - 12:15 @ OLS 001)

CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -O2
DEBUG = -g

OBJECTS = hashTable.o timer.o wordPuzzle.o

a.out:  $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "HashTable implementation is ready to go!"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
	@echo "Cleaned!"

hashTable.o: hashTable.cpp hashTable.h

timer.o: timer.cpp timer.h

wordPuzzle.o: wordPuzzle.cpp timer.h hashTable.h
