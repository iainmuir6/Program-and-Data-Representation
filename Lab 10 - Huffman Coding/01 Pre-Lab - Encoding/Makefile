# Iain Muir, iam9ez
# April 14th, 2020
# Makefile - Pre-Lab 10

CXX = clang++

CXXFLAGS = -Wall -fsanitize=address -fno-omit-frame-pointer -g

OBJECTS = heap.o huffmanenc.o huffmanNode.o 

a.out:	$(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	@echo "Huffman encoder ready to go!"

clean:
	-rm -f *.o *~ *# a.out
	@echo "Cleaned!"


heap.o: heap.cpp heap.h huffmanNode.h
huffmanNode.o: huffmanNode.cpp huffmanNode.h heap.h
huffmanenc.o: huffmanenc.cpp heap.h huffmanNode.h
