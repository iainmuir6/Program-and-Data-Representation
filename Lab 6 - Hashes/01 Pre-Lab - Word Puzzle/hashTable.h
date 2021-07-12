// Iain Muir, iam9ez
// March 2nd, 2020
// hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
using namespace std;


class hashTable {
 public:
  // Constructor
  hashTable(int size);
  // Destructors
  ~hashTable();

  int hash(string s);
  
  void insert(string s);

  bool find(string s);

 private:
  vector<list <string>> v;
};

#endif
