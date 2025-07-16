#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

map < int, int > primes (int x) {
  map < int, int > res;
  for (int i = 2; i * i <= x; ++i) {
    while (x % i == 0) {
      x /= i;
      ++res[i];
    }
  }
  if (x != 1)
    ++res[x];
  return res;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  map < int, int > pows;
  for (int i = 2; i <= n; ++i) {
    map < int, int > here = primes(i);
    for (auto pr: here) 
      pows[pr.first] += pr.second;
  }
  int64_t ans = 1;
  for (auto pr: pows) 
    (ans *= (pr.second + 1)) %= mod;
  cout << ans << '\n';
}