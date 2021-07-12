# Iain Muir, iam9ez
# February 25th, 2020
# Lab Section 102

CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -O2  # Enable all warnings
DEBUG = -g

CLASSES =  BinaryNode.o BinarySearchTree.o BSTPathTest.o

a.out: $(CLASSES)
	$(CXX) $(DEBUG) $(CLASSES) -o a.out
	@echo "BST is ready!"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h
