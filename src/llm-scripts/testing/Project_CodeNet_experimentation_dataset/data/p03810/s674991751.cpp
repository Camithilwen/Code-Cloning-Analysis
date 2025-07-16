#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int N, A[100000];

bool check()
{
  int even = 0, odd = 0;
  for(int i = 0; i < N; i++) {
    if(A[i] & 1) ++odd;
    else ++even;
  }
  if(even & 1) return (true);
  if(odd > 1) return (false);
  for(int i = 0; i < N; i++) {
    if(A[i] == 1) return (false);
    if(A[i] & 1) --A[i];
  }
  int gcd = 0;
  for(int i = 0; i < N; i++) {
    gcd = __gcd(gcd, A[i]);
  }
  for(int i = 0; i < N; i++) {
    A[i] /= gcd;
  }
  return !check();
}

int main()
{
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  if(check()) cout << "First" << endl;
  else cout << "Second" << endl;
}