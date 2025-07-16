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
typedef bitset<705> bs;

// dp[i] is number of colorings with sum equal to i
ll dp[300 * 300 + 5];
const int MOD = 998244353;

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

ll compensate(vector<int>& v) {
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  int tot = 0;
  for(int out: v) {
    for(int i = 90000; i >= out; i--) {
      dp[i] += dp[i-out];
      dp[i] %= MOD;
    }
    tot += out;
  }
  return 3 * dp[tot/2];
}

void solve() {
  int n;
  cin >> n;
  dp[0] = 1;
  ll total = 1;
  int sum = 0;
  vector<int> v;
  for(int i = 0; i < n; i++) {
    total *= 3;
    total %= MOD;
    int t;
    cin >> t;
    v.push_back(t);
    sum += t;
    for(int x = 300 * 300; x >= 0; x--) {
      dp[x] = 2 * dp[x];
      if(x >= t) dp[x] += dp[x-t];
      dp[x] %= MOD;
    }
  }
  ll ret = total;
  for(int i = (sum+1)/2; i <= sum; i++) {
    ret += 3 * (MOD - dp[i]);
    ret %= MOD;
  }
  if(sum%2 == 0) {
    ret += compensate(v);
    ret %= MOD;
  }
  cout << ret << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}
