// Iain Muir, iam9ez
// March 31st, 2020
// mathfun.cpp

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" long product(long x, long y);
extern "C" long power(long x, long y);

/*
C++ implementations of the functions:

long product(long x, long y) {
  long result = 0;
  while ( y > 0 ) {
    result += x;
    y--;
  }
  return result;
}


long power(long x, long y) {
  if (y == 1) {
    return x;
  }
  return product(power(x, y-1) , x);  
}  
*/

int main() {

  // Declare variables
  long x, y;

  // Ask user to input two integers
  cout << "Enter the first integer x: ";
  cin >> x;

  cout << "Enter the second integer y: ";
  cin >> y;

  // Invoke product and power functions
  long prod = product(x, y);
  long pow = power(x, y);

  // Output results
  cout << "The product of " << x << " and " << y << " is " << prod << endl;
  cout << x << " to the power of " << y << " is " << pow << endl;

  return 0;
}
