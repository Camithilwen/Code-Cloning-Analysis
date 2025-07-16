#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  if (M == 1){
    cout << 1 << ' ' << 2 << endl;
    return 0;
  }
 
  if (N % 2 == 1){
    for (int i = 0; i < M; i++) {
      cout << i+1 << ' ' << M*2 - i << endl;
    }
  }
  else {
    for (int i = 0; i < (M+1)/2; i++) {
      cout << i+1 << ' ' << N/2 - i << endl;
    }
    for (int i = 0; i < M/2; i++) {
      cout << N/2 + i + 2 << ' ' << N - i << endl;
    }
  }
}

