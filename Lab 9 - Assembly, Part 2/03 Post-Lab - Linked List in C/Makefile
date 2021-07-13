# Iain Muir, iam9ez
# April 9th, 2020
# Makefile -> Post-Lab 9

CXX = clang
CXXFLAGS = -Wall -fsanitize=address -fno-omit-frame-pointer -g

OBJECTS = linkedlist.o

a.out:	$(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	@echo "Linked List is ready!"

clean:
	-rm -f *.o *~ a.out
	@echo "Cleaned!"

