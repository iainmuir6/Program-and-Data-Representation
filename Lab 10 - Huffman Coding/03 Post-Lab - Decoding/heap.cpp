// Iain Muir, iam9ez
// April 15th, 2020
// heap.cpp

// CODE CITATION:
// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
  huffTree.push_back(NULL);
}

// builds a heap from an unsorted vector
heap::heap(vector<huffmanNode*> huffVec) : heap_size(huffVec.size()) {
  huffmanNode* node = new huffmanNode();
  node->letter ="-";
  node->freq = 0;
  huffTree = huffVec;
  huffTree.push_back(huffTree[0]);
  huffTree[0] = node;
  for ( int i = heap_size/2; i > 0; i-- ) {
    percolateDown(i);
  }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(huffmanNode* node) {
    // a vector push_back will resize as necessary
  huffTree.push_back(node);
    // move it up into the right position
  percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
  // get the value just inserted
  huffmanNode* x = huffTree[hole];
  // while we haven't run off the top and while the
  // value is less than the parent...
  for ( ; (hole > 1) && (x->freq < huffTree[hole/2]->freq); hole /= 2 ) {
    huffTree[hole] = huffTree[hole/2];  // move the parent down
  }
  // correct position found!  insert at that spot
  huffTree[hole] = x;
}

huffmanNode* heap::deleteMin() {
  // make sure the heap is not empty
  if ( heap_size == 0 ) {
    throw "deleteMin() called on empty heap";
  }
  // save the value to be returned
  huffmanNode* ret = huffTree[1];
  // move the last inserted position into the root
  huffTree[1] = huffTree[heap_size--];
  // make sure the vector knows that there is one less element
  huffTree.pop_back();
  // percolate the root down to the proper position
  if (heap_size > 0) {
    percolateDown(1);
  }
  // return the old root node
  return ret;
}

void heap::percolateDown(int hole) {
  // get the value to percolate down
  huffmanNode* x = huffTree[hole];
  // while there is a left child...
  while ( hole*2 <= heap_size ) {
    int child = hole*2; // the left child
    // is there a right child?  if so, is it lesser?
    if ( (child+1 <= heap_size) && (huffTree[child+1]->freq < huffTree[child]->freq) ) {
      child++;
    }
    // if the child is greater than the node...
    if ( x->freq > huffTree[child]->freq ) {
      huffTree[hole] = huffTree[child]; // move child up
      hole = child; // move hole down
    } else
      break;
  }
  // correct position found!  insert at that spot
  huffTree[hole] = x;
}

huffmanNode* heap::findMin() {
  if ( heap_size == 0 ) {
    throw "findMin() called on empty heap";
  }
  return huffTree[1];
}

unsigned int heap::size() {
  return heap_size;
}

void heap::makeEmpty(huffmanNode* node) {
  if (node->left != NULL && node->right != NULL) {
    makeEmpty(node->left);
    makeEmpty(node->right);
  }
  delete node;
  heap_size = 0;
  huffTree.resize(1);
}

bool heap::isEmpty() {
  return heap_size == 0;
}

void heap::generateTree(huffmanNode* node, string p, unordered_map<string, string> codes) {
  if (node == NULL) {
    huffmanNode* root = new huffmanNode();
    huffmanNode* rootLeft = new huffmanNode();
    huffmanNode* rootRight = new huffmanNode();
    root->letter = "-";
    root->left = rootLeft;
    root->right = rootRight;
    insert(root);
    generateTree(rootLeft, p + "0", codes);
    generateTree(rootRight, p + "1", codes);
  }  
  if (codes.find(p) == codes.end() && node != NULL) {
    node->letter = "-";
    huffmanNode* lChild = new huffmanNode();
    huffmanNode* rChild = new huffmanNode();
    node->left = lChild;
    node->right = rChild;
    generateTree(lChild, p + "0", codes);
    generateTree(rChild, p + "1", codes);
  }
  else {
    if (codes[p] != "") {
      node->letter = codes[p];
      node->left = NULL;
      node->right = NULL;
    }
  }  
}

string heap::getLetter(huffmanNode* node, string code, string finalStr) {
  huffmanNode* root = node;
  for (int i = 0; i <= code.length(); i++) {
    if (node->left == NULL && node->right == NULL) {
      finalStr += node->letter;
      node = root;
    }  
    if (code[i] == '0') {
      node = node->left;
    }
    if (code[i] == '1') {
      node = node->right;
    }
  }
  return finalStr;
}  

/*
void heap::print() {
  cout << "(" << huffTree[0]->letter << ") ";
  for ( int i = 1; i <= heap_size; i++ ) {
    cout << huffTree[i]->letter << " ";
    // next line from http://tinyurl.com/mf9tbgm
    bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
    if ( isPow2 ) {
      cout << endl << "\t";
    }
  }
  cout << endl;
}
*/
