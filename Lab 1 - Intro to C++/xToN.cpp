// Iain Muir, iam9ez@virginia.edu
// 1/20/2020
// xToN.cpp

#include <iostream>
using namespace std;

int xton(int x, int n) {
    if (n == 0) {
      return 1;
    }
    if (n == 1) {
      return x;
    }
    return x * xton(x, n-1);
}

int main() {
    int x, n;
    cin >> x;
    cin >> n;
    cout << x << " to the power of " << n << " = " << xton(x,n) << endl;
    return 0;
}
