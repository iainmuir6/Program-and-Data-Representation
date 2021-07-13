// Iain Muir, iam9ez
// Arpil 7th, 2020
// threexinput.cpp

#include <iostream>
#include <cstdlib>
#include "timer.h"
using namespace std;

extern "C" int threexplusone(int x);

/*
C++ implementation:

double threexplusone(long x) {
  if (x == 1) {
    return count;
  }
  if (x % 2 == 0) {
    count++;
    return threexplusone(x/2);
  }
  count++;
  return threexplusone(3*x +1);
}
*/

int main() {
  // Declare variable
  int x;
  double n;

  // Ask user to input an integer
  cout << "Enter the integer value for x: ";
  cin >> x;

  // Ask user for number of times to call subroutine
  cout << "Enter the integer value for n: ";
  cin >> n;

  // Call assembly code - Collatz conjecture
  int steps = threexplusone(x);
  cout << "The number of steps required for " << x << " to reach 1 by following the Collatz conjecture is " << steps << endl;

  // Initialize timer and total time variable
  timer* t = new timer();
  double total = 0;

  // Calculate total runtime of n executions
  for (int i = 0; i < n; i++) {
    t->start();
    threexplusone(x);
    t->stop();

    total += t->getTime();
  }

  // Calculate average runtime of n executions
  double avg = total / n;
  cout << "Average runtime of the subroutine is " << avg << " seconds" << endl;

  return 0;
}
