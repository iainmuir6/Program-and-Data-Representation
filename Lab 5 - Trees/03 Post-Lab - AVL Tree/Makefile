 # Iain Muir, iam9ez
# February 27th, 2020
# Lab Section 102 (11:00-12:15)

CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -O2
DEBUG = -g

AVL_CLASSES = AVLNode.o AVLPathTest.o AVLTree.o

a.out: $(AVL_CLASSES)
	$(CXX) $(DEBUG) $(AVL_CLASSES) -o a.out
	@echo "AVL Tree Implementation is ready!"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

AVLNode.o: AVLNode.cpp AVLNode.h

AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h

AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h
