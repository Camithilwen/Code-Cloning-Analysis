#include "bits/stdc++.h"

using namespace std;

int main() {
  using ull = unsigned long long;
  ull ans[50];
  ull k;
  cin >> k;
  cout << 50 << endl;
  ull j = k / 50;
  int i = k % 50;
  for (auto &x : ans) {
    x = 49 + j;
  }
  for (int a = 0; a < i; ++a) {
    ans[a] += 51;
  }
  for (auto &x : ans) {
    x -= i;
    cout << x << " ";
  }
}