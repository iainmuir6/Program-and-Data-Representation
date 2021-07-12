// Iain Muir, iam9ez
// 2/5/2020
// testPostfixCalc.cpp

#include "postfixCalculator.h"
#include "Stack.h"
#include <iostream>
//#include <stack> -- implementing own Stack class
using namespace std;

int main() {
  cout << "--- STACK CLASS TEST CASE ---" << endl;
  PostfixCalculator pcStack;
  pcStack.pushOn(6);
  pcStack.pushOn(5);
  pcStack.pushOn(2);
  pcStack.pushOn(3);
  pcStack.add();
  pcStack.pushOn(8);
  pcStack.multiply();
  pcStack.add();
  pcStack.pushOn(3);
  pcStack.add();
  pcStack.multiply();
  cout << "Stack Postfix Calculator - Result: " << pcStack.peekTop() << endl;

  cout << "  " << endl;
  
  cout << "--- USER INPUT TEST CASE ---" << endl;
  PostfixCalculator pc;
  string token;
  while (cin >> token) {
    if (token == "+") {
      pc.add();
      continue;
    }
    if (token == "-") {
      pc.subtract();
      continue;
    }
    if (token == "*") {
      pc.multiply();
      continue;
    }
    if (token == "/") {
      pc.divide();
      continue;
    }
    if (token == "~") {
      pc.negation();
      continue;
    }
    int num = stoi(token);
    pc.pushOn(num);
  }
  cout << "Postfix Calculator UI - Result: " << pc.peekTop() << endl;

  cout << "  " << endl;

  cout << "--- TEST CASE 1: Expected = 288 ---" << endl;
  PostfixCalculator pc1;
  pc1.pushOn(6);
  pc1.pushOn(5);
  pc1.pushOn(2);
  pc1.pushOn(3);
  pc1.add();
  pc1.pushOn(8);
  pc1.multiply();
  pc1.add();
  pc1.pushOn(3);
  pc1.add();
  pc1.multiply();
  cout << "Postfix Calculator TC1 - Result: " << pc1.peekTop() << endl;

  cout << "  " << endl;

  cout << "--- TEST CASE 2: Expected = -35 ---" << endl;
  PostfixCalculator pc2;
  pc2.pushOn(5);
  pc2.pushOn(4);
  pc2.negation();
  pc2.multiply();
  pc2.pushOn(35);
  pc2.multiply();
  pc2.pushOn(3);
  pc2.pushOn(2);
  pc2.subtract();
  pc2.pushOn(11);
  pc2.pushOn(9);
  pc2.add();
  pc2.multiply();
  pc2.divide();
  cout << "Postfix Calculator TC2 - Result: " << pc2.peekTop() << endl;

  cout << "  " << endl;
  return 0;  
};
