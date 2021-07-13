// Iain Muir, iam9ez
// April 15th, 2020
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
  void generateTree(huffmanNode* node, string p, unordered_map<string, string> codes);
  string getLetter(huffmanNode* node, string code, string finalStr);
  //void print();

  vector<huffmanNode*> huffTree;
  unsigned int heap_size;
  void percolateUp(int hole);
  void percolateDown(int hole);
  unordered_map<string,string> prefixCodes;

  friend huffmanNode;
};

#endif
