#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

typedef long long ll;

void solve() {
  int N;
  cin >> N;
  int A[N];
  for (int& i: A) cin >> i;

  ll ans = 0;
  const int mod = 1e9 + 7;
  int suff[N] = {0};
  suff[N - 1] = A[N - 1];
  for (int i = N - 2; i >= 0; i--) 
    suff[i] = (A[i] + suff[i + 1]) % mod;
  for (int i = 0; i < N - 1; i++) ans = (ans + (1ll * A[i] * suff[i + 1]) % mod) % mod;

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // int t;
  // cin >> t;
  // while (t--) {
  solve();
  // cout << nl;
  // }

  return 0;
}