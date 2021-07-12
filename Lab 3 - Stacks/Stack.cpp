// Iain Muir, iam9ez
// 2/5/2020
// Stack.cpp

#include <iostream>
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"
#include "Stack.h"
using namespace std;

// constructor
Stack::Stack() {
  //List l;
}

// destructor
Stack::~Stack() {
  l.makeEmpty();
}

// push
void Stack::push(int x) {
  l.insertAtTail(x);
}

// top
int Stack::top() {
  return l.last().current->value;
}

// pop
void Stack::pop() {
  l.remove(l.last().current->value);
}

// empty
bool Stack::empty() {
  if (l.isEmpty()) {
    return true;
  }
  return false;
}  
