#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
const ll INF = 1LL << 62;
int main() {
  //
  ll n;
  cin >> n;
  vl a(n);
  rep(i, n) cin >> a[i];
  ll s = 0;
  rep(i, n) s ^= a[i];
  ll ans = s;
  rep(i, n) { a[i] &= ~s; }
  int r = 0;
  for (int i = 60; i >= 0; i--) {
    int j = r;
    for (; j < n; j++) {
      if (a[j] >> i & 1) {
        swap(a[r], a[j]);
        break;
      }
    }
    if (j == n) continue;
    rep(k, n) {
      if (k == r) continue;
      if (a[k] >> i & 1) a[k] ^= a[r];
    }
    ++r;
  }

  ll x = 0;
  rep(j, r) {
    x = x ^ a[j];

  }
  ans += x * 2;
  cout << ans << endl;
  return 0;
}
