// Iain Muir, iam9ez
// 2/11/2020
// inlab4.cpp

#include <iostream>
#include <climits>
#include <cfloat>
using namespace std;

int main() {
  cout << "----------- REPRESENTATION IN MEMORY SECTION -----------" << endl;
  // size of
  cout << "int: " << sizeof(int) << endl;
  cout << "unsigned int: " << sizeof(unsigned int) << endl;
  cout << "float: " << sizeof(float) << endl;
  cout << "double: " << sizeof(double) << endl;
  cout << "char: " << sizeof(char) << endl;
  cout << "bool: " << sizeof(bool) << endl;
  cout << "int*: " << sizeof(int*) << endl;
  cout << "char*: " << sizeof(char*) << endl;
  cout << "double* " << sizeof(double*) << endl;

  cout << "-----------" << endl;

  // climits
  cout << "int: " << INT_MAX  << endl;
  cout << "unsigned int: " << UINT_MAX << endl;
  cout << "float: " << FLT_MAX << endl;
  cout << "double: " << DBL_MAX << endl;
  cout << "char: " << CHAR_MAX << endl;

  cout << "-----------" << endl;
  
  int i = 1;
  unsigned int ui = 1;
  bool b = true;
  float f = 1.0;
  char c = '1';
  double d = 0.0;
  int* iPoint = NULL;
  char* cPoint = NULL;
  double* dPoint = NULL;

  cout << "i: " << i << endl;
  cout << "ui: " << ui << endl;
  cout << "b: " << b << endl;
  cout << "f: " << f << endl;
  cout << "c: " << c << endl;
  cout << "d: " << d << endl;
  //cout << "iPoint: " << iPoint << endl;
  //cout << "cPoint: " << cPoint << endl;
  //cout << "dPoint: " << dPoint << endl;

  cout << " " << endl;
  cout << "---------- PRIMITIVE ARRAYS SECTION  -----------" << endl;
  
  int IntArray[5] = {1,2,3,4,5};
  int IntArray2D[6][5] =
  //  c0,c1,c2,c3,c4
    {
      {1,2,3,4,5},      //r0
      {6,7,8,9,10},     //r1
      {11,12,13,14,15}, //r2
      {16,17,18,19,20}, //r3
      {21,22,23,24,25}, //r4
      {26,27,28,29,30}  //r5
    };
  
  char CharArray[10];
  char CharArray2D[6][5];
  
  cout << "Address of IntArray2D: " << &IntArray2D << endl;
  cout << "[0][0] : " << &IntArray2D[0][0] << endl;
  cout << "[0][1] : " << &IntArray2D[0][1] << endl;
  cout << "[0][2] : " << &IntArray2D[0][2] << endl;
  cout << "[0][3] : " << &IntArray2D[0][3] << endl;
  cout << "[0][4] : " << &IntArray2D[0][4] << endl;
  cout << "[0][5] : " << &IntArray2D[0][5] << endl;

  cout << "[1][5] : " << &IntArray2D[1][5] << endl;
  cout << "[2][5] : " << &IntArray2D[2][5] << endl;
  cout << "[3][5] : " << &IntArray2D[3][5] << endl;
  cout << "[4][5] : " << &IntArray2D[4][5] << endl;
  cout << "[5][5] : " << &IntArray2D[5][5] << endl;
  cout << "[6][5] : " << &IntArray2D[6][5] << endl;
};
 
