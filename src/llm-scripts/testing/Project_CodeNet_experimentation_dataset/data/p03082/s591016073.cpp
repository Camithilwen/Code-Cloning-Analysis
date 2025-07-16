#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<pii, int> ppiii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> query;

ll facs[205];
ll ifacs[205];
const int MOD = 1000000007;

ll modpow(ll b, ll e, ll m) {
  ll r = 1;
  while(e) {
    if(e%2) {
      r *= b;
      r %= m;
    }
    b *= b;
    b %= m;
    e /= 2;
  }
  return r;
}

int l[205];
bool found[205][100005];
ll dp[205][100005];

int n;
ll solve(int k, int x) {
  if(k == 0) return x;
  if(found[k][x]) return dp[k][x];
  found[k][x] = true;
  dp[k][x] = solve(k-1, x%l[k-1]) + (k-1) * solve(k-1, x);
  dp[k][x] %= MOD;
  dp[k][x] *= modpow(k, MOD-2, MOD);
  dp[k][x] %= MOD;
  return dp[k][x];
}

void solve() {
  int m;
  cin >> n >> m;
  facs[0] = 1;
  for(int i = 1; i <= n; i++) {
    facs[i] = facs[i-1] * i;
    facs[i] %= MOD;
  }
  ifacs[n] = modpow(facs[n], MOD-2, MOD);
  for(int i = n-1; i >= 0; i--) {
    ifacs[i] = ifacs[i+1] * (i+1);
    ifacs[i] %= MOD;
  }
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  sort(l, l+n);
  ll ret = solve(n, m);
  ret *= facs[n];
  ret %= MOD;
  cout << ret << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << " ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}
