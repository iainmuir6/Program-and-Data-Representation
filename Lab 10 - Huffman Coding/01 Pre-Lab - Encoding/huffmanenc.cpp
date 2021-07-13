// Iain Muir, iam9ez
// April 14th, 2020
// huffmanenc.cpp

#include <unordered_map>
#include <vector>
#include <iostream> // included so we can use cout
#include <fstream>  // file I/O
#include <cstdlib>  // cstdlib is where exit() lives
#include <stdio.h>
#include <ctype.h>
#include <string>
#include "heap.h"
#include "huffmanNode.h"

using namespace std;

// we want to use parameters
int main(int argc, char** argv) {

// ----------------------------------------- STEP 1 -----------------------------------------
  
    // verify the correct number of parameters
  if (argc != 2) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }

  // attempt to open the supplied file
  // ifstream stands for "input file stream"
  ifstream file(argv[1]);
  // if the file wasn't found, output an error message and exit

  if (!file.is_open()) {
    cout << "Unable to open '" << argv[1] << "' for reading" << endl;
    exit(2);
  }

  unordered_map<char, int> freqMap;

  // read in characters one by one, until reading fails (we hit the end of the file)
  char g;
  while (file.get(g)) {
    if (!isprint(g)) {
      continue;
    }
    if (freqMap.find(g) == freqMap.end()) {
      freqMap[g]= 1;
      continue;
    }
    freqMap[g]++;
  }
  
  
  // once we hit the end of the file we are marked as "failed", so clear that
  // then "seek" to the beginning of the file to start again
  file.clear(); // Clears the _state_ of the file, not its contents!
  file.seekg(0);

// ----------------------------------------- STEP 2 -----------------------------------------

  heap huffTree;
  
  for ( auto it = freqMap.begin(); it != freqMap.end(); ++it ) {
    huffmanNode* node = new huffmanNode();
    node->letter = it->first;
    node->freq = it->second;
    node->left = NULL;
    node->right = NULL;
    huffTree.insert(node);
  }

  /*
  for (int i = 0; i < huffVec.size(); i++) {
    cout << huffVec[i]->letter << huffVec[i]->freq << endl;
  }  
  */
  
  //huffTree->print();

// ----------------------------------------- STEP 3 -----------------------------------------

  
  while (huffTree.size() != 1) {
    huffmanNode* lChild = huffTree.deleteMin();
    huffmanNode* rChild = huffTree.deleteMin();
    huffmanNode* dummy = new huffmanNode();
    dummy->letter = '-';
    dummy->freq = lChild->freq + rChild->freq;
    dummy->left = lChild;
    dummy->right = rChild;
    huffTree.insert(dummy);
  }  
  
// ----------------------------------------- STEP 4 -----------------------------------------

  //huffTree->print();
  unordered_map<char,string> prefixCodes = huffTree.pathname(huffTree.findMin(), "");

  cout << "----------------------------------------" << endl;

// ----------------------------------------- STEP 5 -----------------------------------------

  string file_string;
  string encoded_string;
  // Read the file again, and print to the screen
  while (file.get(g)) {
    file_string += g;
    encoded_string += prefixCodes[g];
    cout << prefixCodes[g] << " ";
  }
  
  cout << "" << endl;
  cout << "----------------------------------------" << endl;

  cout << "There are a total of " << file_string.length() - 1 << " symbols that are encoded." << endl;
  cout << "There are " << freqMap.size() << " distinct symbols used." << endl;
  cout << "There were " <<  (file_string.length() - 1) * 8 << " bits in the original file." << endl;
  cout << "There were " << encoded_string.length() << " bits in the compressed file." << endl;
  cout << "This gives a compression ratio of " << ( float((file_string.length()-1)  * 8) / float(encoded_string.length()) )  << "." << endl;
  cout << "The cost of the Huffman tree is " << ( float(encoded_string.length()) / float(file_string.length() - 1) )  << " bits per character." << endl;


  huffTree.makeEmpty(huffTree.findMin());
  file.close();
  
// ------------------------------------------------------------------------------------------
  /*
  ofstream file2;
  file2.open("encoded1.txt");
  for ( auto it = prefixCodes.begin(); it != prefixCodes.end(); ++it ) {
    file2 << it->first << " " << it->second << endl;
  }  
  file2 << "----------------------------------------\n"
  char encoded_string = '';
  // Read the file again, and print to the screen
  while (file.get(g)) {
    encoded_string += g;
    file2 << prefixCodes[g] << " ";
  }
  file2 << "----------------------------------------\n";
  file2 << "There are a total of " << len(file) << "symbols that are encoded.";
  file2 << "There are " << freqMap.size() << " distinct symbols used.";
  file2 << "There were " <<  int(len(file)) * 8 << "bits in the original file.";
  file2 << "There were " << len(encoded_string) << " bits in the compressed file.";
  file2 << "This gives a compression ratio of " << ( (int(len(file)) * 8) / (int(len(encoded_string))) )  << ".";
  file2 << "The cost of the Huffman tree is " << ( int(len(encoded_string)) / (int(len(file))) )  << "  bits per character.";
  // close the files
  file.close();
  file2.close();
  */

  return 0;
}


