#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int dmin = 100;
  for (int i = 0; i < N; i++) {
    int A, d = 0;
    cin >> A;
    
    while (A % 2 == 0) {
      A /= 2;
      d++;
    }
    
    dmin = min(dmin, d);
  }
  
  cout << dmin << endl;
}
