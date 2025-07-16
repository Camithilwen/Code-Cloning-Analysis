#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define append push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<ll> enum_divisors(ll N) {
  vector<ll> res;
  for (ll i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res.push_back(i);
      if (N/i != i) res.push_back(N/i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main() {
  ll n,m;
  cin >> n >> m;
  const auto &res = enum_divisors(m);
  ll ans = 0;
  for (ll i : res) {
    if (n * i <= m) ans = i;
  }
  cout << ans << endl;
}