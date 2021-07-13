// Iain Muir, iam9ez
// April 14th, 2020
// huffmanNode.h

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <unordered_map>
using namespace std;

class huffmanNode {
 public:
  huffmanNode();
  ~huffmanNode();

  huffmanNode* left;
  huffmanNode* right;
  char letter;
  int freq;

  friend class heap;
};  

#endif
