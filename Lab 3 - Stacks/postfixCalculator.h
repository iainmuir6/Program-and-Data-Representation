// Iain Muir, iam9ez
// 2/5/2020
// postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "Stack.h"
//#include <stack>  -- implementing own Stack class
using namespace std;

class PostfixCalculator {
 public:
  // default constructor
  PostfixCalculator();
  /// destructor
  ~PostfixCalculator();
  // push
  void pushOn(int num);
  // pop
  void popOff();
  // top / peek
  int peekTop();
  // add
  void add();
  // multiply
  void multiply();
  // divide
  void divide();
  // subtract
  void subtract();
  // unary negation
  void negation();

 private:
  Stack s;
};

#endif
