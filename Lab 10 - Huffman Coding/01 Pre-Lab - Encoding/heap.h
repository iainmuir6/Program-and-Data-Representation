// Iain Muir, iam9ez
// April 14th, 2020
// heap.h

// CODE CITATION:
// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <unordered_map>
#include "huffmanNode.h"

using namespace std;

class heap {
public:
  heap();
  heap(vector<huffmanNode*> huffVec);
  ~heap();
  void insert(huffmanNode* node);
  huffmanNode* findMin();
  huffmanNode* deleteMin();
  unsigned int size();
  void makeEmpty(huffmanNode* node);
  bool isEmpty();
  void print();
  unordered_map<char,string> pathname(huffmanNode* node, string p);

  vector<huffmanNode*> huffTree;
  unsigned int heap_size;
  void percolateUp(int hole);
  void percolateDown(int hole);
  unordered_map<char,string> prefixCodes;

  friend huffmanNode;
};

#endif
