// Iain Muir, iam9ez
// 2/13/2020
// bitCounter.cpp

#include <iostream>
#include <string>
using namespace std;

int bitCounter(int n) {
  if (n == 1) {
    return 1;
  }
  if (n % 2 == 0) {
    return bitCounter(n/2);
  }  
  return 1 + bitCounter(n/2);
}

int main (int argc, char **argv) {
   cout << "---------- COMMAND-LINE  ---------- " << endl;
  for (int i = 1; i < argc; i++) {
    cout << "bitCounter(" << argv[i] << ") : " << bitCounter(stoi(argv[i])) << endl;
  }
  
  cout << " " << endl;
  
  cout << "---------- NORMAL MAIN ----------" << endl;

  cout << "bitCounter(64): " << bitCounter(64) << endl;
  cout << "bitCounter(60): " << bitCounter(60) << endl;
  cout << "bitCounter(100): " << bitCounter(100) << endl;
  cout << "bitCounter(55): " << bitCounter(55) << endl;
  cout << "bitCounter(111): " << bitCounter(111) << endl;
  cout << "bitCounter(6): " << bitCounter(6) << endl;
}  
