// Iain Muir, iam9ez
// April 15th, 2020
// huffmandec.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include "heap.h"
#include "huffmanNode.h"
using namespace std;

// main(): we want to use parameters
int main (int argc, char** argv) {

// ---------------------------------------- STEP 1 ----------------------------------------
  // verify the correct number of parameters
  if (argc != 2) {
    cout << "Must supply the input file name as the only parameter" << endl;
    exit(1);
  }

  // attempt to open the supplied file
  // must be opened in binary mode as otherwise trailing whitespace is discarded
  ifstream file(argv[1], ifstream::binary);
  // report any problems opening the file and then exit
  if (!file.is_open()) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }

  unordered_map <string, string> prefixCodes;
  
  // read in the first section of the file: the prefix codes
  while (true) {
    string character, prefix;
    // read in the first token on the line
    file >> character;
    // did we hit the separator?
    if (character[0] == '-' && character.length() > 1) {
      break;
    }
    // check for space
    if (character == "space") {
      character = " ";
    }
    // read in the prefix code
    file >> prefix;
    
    // do something with the prefix code
    prefixCodes[prefix] = character;
  } 
  
// ---------------------------------------- STEP 2 ----------------------------------------

  heap huffTree;
  huffTree.generateTree(NULL, "", prefixCodes);

// -------------------------------------- STEP 3/4/5 --------------------------------------

  
  // read in the second section of the file: the encoded message
  stringstream sstm;
  while (true) {
    string bits;
    // read in the next set of 1's and 0's
    file >> bits;
    // check for the separator
    if (bits[0] == '-') {
      break;
    }
    // add it to the stringstream
    sstm << bits;
  }

  string allbits = sstm.str();
  // at this point, all the bits are in the 'allbits' string
  //cout << "All the bits: " << allbits << endl;

  string str = "";
  string decodedText = huffTree.getLetter(huffTree.findMin(), allbits, str);
  cout << decodedText << endl;

  // deallocate memory
  huffTree.makeEmpty(huffTree.findMin());
  // close the file before exiting
  file.close();
 
  return 0;
}
