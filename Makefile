# Iain Muir, iam9ez
# April 21st, 2020
# Makefile - Pre-Lab 11

CXX = clang++

CXXFLAGS = -Wall -fsanitize=address -fno-omit-frame-pointer -g

OBJECTS = topographical.o 

a.out:	$(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	doxygen
	@echo "Topographical Sort and Doxygen documentation is ready to go!"

clean:
	-rm -f *.o *~ *# a.out
	@echo "Cleaned!"

topographical.o: topographical.cpp
