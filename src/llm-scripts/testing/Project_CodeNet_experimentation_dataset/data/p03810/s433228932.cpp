#include <bits/stdc++.h>
using namespace std;

int N;
#define MAX_N 100000
int A[MAX_N];
bool F;

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  cin >> N;
  for(int i = 0; i < N; ++i) cin >> A[i];
  F = true;
  while(true) {
    int c = 0, o = -1;
    for(int i = 0; i < N; ++i) {
      if(A[i] % 2 == 0) ++c;
      else o = i;
    }
    if(c % 2 == 1) break;
    F = !F;
    if(c != N - 1 || A[o] == 1) break;
    --A[o];
    int g = 0; for(int i = 0; i < N; ++i) g = gcd(g, A[i]);
    for(int i = 0; i < N; ++i) A[i] /= g;
  }
  cout << (F ? "First" : "Second") << endl;
  return 0;
}
