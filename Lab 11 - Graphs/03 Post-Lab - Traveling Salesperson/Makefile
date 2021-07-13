# Iain Muir, iam9ez
# April 22nd, 2020
# Makefile <Post-Lab 11>

CXX = clang++

CXXFLAGS = -O2 -Wall -fsanitize=address -fno-omit-frame-pointer -g

OBJECTS = traveling.o middleearth.o

a.out:	$(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	doxygen
	@echo "Travelling Salesperon Solution ready to go!"
	@echo "Doxygen Documentation ready to go!"

middleearth.o: middleearth.cpp middleearth.h

traveling.o: traveling.cpp middleearth.h
