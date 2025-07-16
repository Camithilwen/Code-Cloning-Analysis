#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> a;

long long solve();

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long res = 0;
  for (int i = 1; i < n; ++i)
    if (a[i] > a[i - 1] + 1) return -1;
  if (a[0] != 0) return -1;
  for (int i = 1; i < n; ++i)
    if (a[i] - 1 == a[i - 1])
      ++res;
    else
      res += a[i];
  return res;
}
