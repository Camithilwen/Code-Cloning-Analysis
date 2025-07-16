#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

const ll INF = 1e9;
const long long INFL = 1LL<<60;

int main() {
  int m;
  cin >> m;

  map<ll, ll> mp;

  rep(i, m) {
    ll d, c;
    cin >> d >> c;
    mp[d] += c;
  }

  ll ans = 0;

  bool flag = true;
  while (flag) {
    flag = false;
    rep(i, 10) {
      if (mp[i] > 1) flag = true;
      ll num = mp[i] / 2;
      ans += num;
      mp[i] -= num * 2;
      if (i + i < 10) mp[i+i] += num;
      else {
        mp[1] += num;
        mp[(i + i) % 10] += num;
      }
    }
  }

  vector<ll> a;
  rep(i, 10) {
    if (mp[i] != 0) a.push_back(i);
  }

  while (a.size() > 1) {
    int x = a.back(); a.pop_back();
    int y = a.back(); a.pop_back();
    if (x + y < 10) a.push_back(x + y);
    else {
      a.push_back(1);
      a.push_back((x + y) % 10);
    }
    ans++;
  }

  cout << ans << endl;

  return 0;
}
