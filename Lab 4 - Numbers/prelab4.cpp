// Iain Muir, iam9ez
// 2/10/2020
// prelab4.cpp

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// sizeOfTest
void sizeOfTest() {
  cout << "int: " << sizeof(int) << endl;
  cout << "unsigned int: " << sizeof(unsigned int) << endl;
  cout << "float: " << sizeof(float) << endl;
  cout << "double: " << sizeof(double) << endl;
  cout << "char: " << sizeof(char) << endl;
  cout << "bool: " << sizeof(bool) << endl;
  cout << "int*: " << sizeof(int*) << endl;
  cout << "char*: " << sizeof(char*) << endl;
  cout << "double* " << sizeof(double*) << endl;
}

// outputBinary
void outputBinary(int x) {
  int initial = x; // initial value of x for final print statement
  
  string binaryString = "";
  for (int i = 31; i >= 0; i--) {
    if ( pow(2, i)  > x ) {
      binaryString += "0";
      continue;
    }
    binaryString += "1";
    x = x - pow(2, i);
  }
  
  string finalBinaryString = "";
  for (int i = 1; i <= binaryString.length(); i++) {
    if (i % 4 == 0) {
      finalBinaryString += binaryString[i-1];
      finalBinaryString += " ";
      continue;
    }
    finalBinaryString += binaryString[i-1];
  }
  
  cout << "outputBinary(" << to_string(initial) << ") ==> " << finalBinaryString << endl;
}  

// overflow
void overflow() {
  unsigned int max = 4294967295;
  max++;
  cout << "Result: " << to_string(max) << endl;
  cout << " " << endl;
  cout << "When you add 1 to an unsigned int with its maximum value, the program does not halt and you get an answer of 0. This occurs because when you go past the upper bound of an int it wraps around to its lower bound; since the variable 'max' is of type unsigned int (which can have values from 0 to 4,294,967,295), the lower bound that is wrapped around to is zero." << endl;
}  

// main testing
int main() {  
  cout << "-- outputBinary Function--" << endl;
  string num;
  cout << "Enter one integer: ";
  cin >> num;
  int finalNum = stoi(num);
  outputBinary(finalNum);

  cout << " " << endl;
  cout << "-- sizeOf Function--" << endl;
  sizeOfTest();

  cout << " " << endl;
  cout << "-- overflow Function--" << endl;
  overflow();
};  
