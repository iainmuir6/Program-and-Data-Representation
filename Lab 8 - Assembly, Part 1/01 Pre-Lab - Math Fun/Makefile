# Iain Muir, iam9ez
# March 31st, 2020
# Makefile

# Code has been formatted for compilation on a x64 Linux machine.
#	 Change ASFLAGS to -f macho64 -g for macOS

CXX = clang++
CXXFLAGS = -Wall -g
AS = nasm
ASFLAGS = -f elf64 -g			# -f macho64 -g

OBJECTS = mathlib.o mathfun.o

.SUFFIXES: .o .cpp

.SUFFIXES: .o .s

a.out:	$(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~ a.out
	@echo "Cleaned!"
