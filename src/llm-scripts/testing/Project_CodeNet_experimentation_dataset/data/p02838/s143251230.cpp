#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int n;
int cnt = 62;
vector<ll> vec;
ll mod = 1e9+7;

ll solve() {
  vector<vector<int>> sum_zero(n+1, vector<int>(cnt, 0));
  vector<vector<int>> sum_one(n+1, vector<int>(cnt, 0));

  ll ans = 0;
  reps(i, 1, n+1) {
    rep(j,cnt) {
      if (vec.at(i-1) >> j & 1ll) {
        sum_one.at(i).at(j) = sum_one.at(i-1).at(j) + 1;
        sum_zero.at(i).at(j) = sum_zero.at(i-1).at(j);
      } else {
        sum_one.at(i).at(j) = sum_one.at(i-1).at(j);
        sum_zero.at(i).at(j) = sum_zero.at(i-1).at(j) + 1;
      }
    }
  }
  rep(i, n-1) {
    ll t = 1;
    rep(j, cnt) {
      ll v;
      if (vec.at(i) >> j & 1ll) {
        v = (sum_zero.at(n).at(j) - sum_zero.at(i+1).at(j));
      } else {
        v = (sum_one.at(n).at(j) - sum_one.at(i+1).at(j));
      }
      ans += v * t;
      ans %= mod;
      t *= 2;
      t %= mod;
    }
  }
  return ans;
}

int main()
{ 
  cin >> n;
  vec.resize(n);
  rep(i, n) cin >> vec.at(i);
  cout << solve() << endl;
  
  return 0;
}