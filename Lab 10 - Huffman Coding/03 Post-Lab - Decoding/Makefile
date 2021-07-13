# Iain Muir, iam9ez
# April 15th, 2020
# Makefile - Post-Lab 10

CXX = clang++

CXXFLAGS = -Wall -fsanitize=address -fno-omit-frame-pointer -g

OBJECTS = heap.o huffmandec.o huffmanNode.o 

a.out:	$(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	@echo "Huffman decoder ready to go!"

clean:
	-rm -f *.o *~ *# a.out
	@echo "Cleaned!"


heap.o: heap.cpp heap.h huffmanNode.h
huffmanNode.o: huffmanNode.cpp huffmanNode.h heap.h
huffmandec.o: huffmandec.cpp heap.h huffmanNode.h
