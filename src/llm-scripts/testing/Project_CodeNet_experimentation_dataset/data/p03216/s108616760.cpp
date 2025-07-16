#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using T = tuple<ll, ll, ll>;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  string s;
  cin >> n >> s >> q;
  rep(_, q) {
    int k;
    cin >> k;
    vector<T> res(n);
    ll ans = 0;
    rep(i, n) {
      if (i)
        res[i] = res[i-1];
      if (i-k >= 0) {
        if (s[i-k] == 'D') {
          get<2>(res[i]) -= get<1>(res[i]);
          get<0>(res[i])--;
        }
        if (s[i-k] == 'M')
          get<1>(res[i])--;
      }
      if (s[i] == 'D')
        get<0>(res[i])++;
      if (s[i] == 'M') {
        get<1>(res[i])++;
        get<2>(res[i]) += get<0>(res[i]);
      }
      if (s[i] == 'C')
        ans += get<2>(res[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}