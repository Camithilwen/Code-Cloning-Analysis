#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N;
  M = N;
  int sum = 0;
  
  for (int i=8; i>=0; i--) {
    int W=1;
    for (int j=0; j<i; j++){
      W *= 10;
    }
    int x;
    x = N / W;
    sum += x;
    N = N - x*W;
  }
  if (M % sum == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}