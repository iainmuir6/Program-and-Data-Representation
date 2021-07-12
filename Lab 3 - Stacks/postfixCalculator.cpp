// Iain Muir, iam9ez
// 2/3/2020
// postfixCalculator.cpp

#include "postfixCalculator.h"
#include "Stack.h"
#include <iostream>
//#include <stack>
using namespace std;

// default constructor
PostfixCalculator::PostfixCalculator() {
}

// destructor
PostfixCalculator::~PostfixCalculator() { } 

// push
void PostfixCalculator::pushOn(int num) {
  s.push(num);
}

// pop
void PostfixCalculator::popOff() {
  if (s.empty()) {
    cout << "Empty List" << endl;
  }
  return s.pop();
}

// top/peek
int PostfixCalculator::peekTop() {
  if (s.empty()) {
    cout << "Empty List" << endl;
    return 0;
  }
  return s.top();
}

// add
void PostfixCalculator::add() {
  if (s.empty()) {
    cout << "Empty List" << endl;
  }
  int num1 = s.top();
  s.pop();
  int num2 = s.top();
  s.pop();
  int finalNum = num1 + num2;
  s.push(finalNum);
}

// multiply
void PostfixCalculator::multiply() {
  if (s.empty()) {
    cout << "Empty List" << endl;
  }
  int num1 = s.top();
  s.pop();
  int num2 = s.top();
  s.pop();
  int finalNum = num1 * num2;
  s.push(finalNum);
}

// divide
void PostfixCalculator::divide() {
  if (s.empty()) {
    cout << "Empty List" << endl;
  }
  int num1 = s.top();
  s.pop();
  int num2 = s.top();
  s.pop();
  int finalNum = num2/num1;
  s.push(finalNum);
}

// subtract
void PostfixCalculator::subtract() {
  if (s.empty()) {
    cout << "Empty List" << endl;
  }
  int num1 = s.top();
  s.pop();
  int num2 = s.top();
  s.pop();
  int finalNum = num2 - num1;
  s.push(finalNum);
}

// unary negation
void PostfixCalculator::negation() {
  if (s.empty()) {
    cout << "Empty List" << endl;
  }
  int num = s.top();
  s.pop();
  int finalNum = num * -1;
  s.push(finalNum);
}
