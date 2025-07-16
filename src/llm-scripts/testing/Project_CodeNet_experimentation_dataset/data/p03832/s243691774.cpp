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
typedef pair<int, pii> pipii;
typedef pair<double, double> pdd;
typedef pair<ll, pii> key;

ll facs[1005];
ll ifacs[1005];
const int MOD = 1000000007;

ll modpow(ll b, ll e, ll m) {
  ll r = 1;
  while(e) {
    if(e%2) {
      r*=b;
      r%=m;
    }
    b*=b;
    b%=m;
    e/=2;
  }
  return r;
}

ll solve(int sz, int num) {
  ll ret = facs[sz*num];
  for(int i = 0; i < num; i++) {
    ret *= ifacs[sz];
    ret %= MOD;
  }
  ret *= ifacs[num];
  ret %= MOD;
  // cout << num << " groups of size " << sz << " is " << ret << endl;
  return ret;
}

ll dp[1005];
ll ndp[1005];

void solve() {
  facs[0] = 1;
  for(int i = 1; i <= 1000; i++) {
    facs[i] = facs[i-1] * i;
    facs[i] %= MOD;
  }
  ifacs[1000] = modpow(facs[1000], MOD-2, MOD);
  for(int i = 999; i >= 0; i--) {
    ifacs[i] = ifacs[i+1] * (i+1);
    ifacs[i] %= MOD;
  }
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  dp[0] = 1;
  for(int x = a; x <= b; x++) {
    memset(ndp, 0, sizeof(ndp));
    for(int y = c; y <= d; y++) {
      for(int i = 0; i + x*y <= n; i++) {
        if(dp[i] == 0) continue;
        ll scale = facs[i+x*y];
        scale *= ifacs[x*y];
        scale %= MOD;
        scale *= ifacs[i];
        scale %= MOD;
        scale *= solve(x, y);
        scale %= MOD;
        ndp[i+x*y] += dp[i] * scale;
        ndp[i+x*y] %= MOD;
      }
    }
    for(int i = 0; i <= n; i++) {
      dp[i] += ndp[i];
      dp[i] %= MOD;
    }
  }
  cout << dp[n] << "\n";
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
