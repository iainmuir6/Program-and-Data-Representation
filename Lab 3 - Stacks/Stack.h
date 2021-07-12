// Iain Muir, iam9ez
// 2/5/2020
// Stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"
using namespace std;

class Stack {
 public:
  // default constructor
  Stack();
  // destructor
  ~Stack();
  // push
  void push(int x);
  // top
  int top();
  // pop
  void pop();
  // empty
  bool empty();
  
 private:
  List l;
  friend class PostfixCalculator; // allows PostfixCalculator to access Stack functions
};

#endif
