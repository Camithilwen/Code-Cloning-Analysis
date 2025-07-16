#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, N, d, S;
  cin >> X;
  N = X;
  
  for (int i = 0; i < 9; i++) {
    if (N != 0) {
      d = N % 10;
      N /= 10;
      S += d;
    }    
    else {
      break;
    }
  }
  
  if (X % S == 0) {
    cout << "Yes" << endl;
  }
  
  else {
    cout << "No" << endl;
  }
}