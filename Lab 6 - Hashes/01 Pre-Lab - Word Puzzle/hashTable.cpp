// Iain Muir, iam9ez
// March 2nd, 2020
// hashTable.cpp

#include "hashTable.h"
#include <iostream>
#include <vector>
#include <list>
using namespace std;


hashTable::hashTable(int size) {
  v.resize(size);
}

hashTable::~hashTable() {
  // delete!
}

int hashTable::hash(string s) {
  int sumASCII = 0;
  for (int i = 0; i < s.length(); i++) {
    int ascii = int(s[i]);
    sumASCII += ascii;
  }
  return (sumASCII * 41) % v.size();
}
  
void hashTable::insert(string s) {
  int hashIndex = hash(s);
  v.at(hashIndex).push_back(s);
}  

bool hashTable::find(string s) {
  int hashIndex = hash(s);

  for (string i : v.at(hashIndex)) {
    if (i == s) {
      return true;
    }
  }
  return false;
}  
