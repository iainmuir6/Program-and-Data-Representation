// Iain Muir, iam9ez
// April 15th, 2020
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
  string letter;
  int freq;

  friend class heap;
};  

#endif
