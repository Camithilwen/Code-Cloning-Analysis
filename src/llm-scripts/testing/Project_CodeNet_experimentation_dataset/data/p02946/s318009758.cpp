#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int K,X; cin >> K >> X;
  int N = X+K-1;
  int M = X-K+1;
  for(int i=M; i<=N; i++) {
    cout << i << " ";
  }
  return 0;
}