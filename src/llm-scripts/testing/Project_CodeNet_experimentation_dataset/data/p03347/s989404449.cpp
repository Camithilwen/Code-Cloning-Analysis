#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define per(i,n) for (int i = n - 1; i >= 0; --i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
static const double pi = 3.141592653589793;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  ll prev; cin >> prev;
  bool ok = 1;

  if(prev > 0) {
    ok = 0;
  }

  ll ans = 0;
  rep(i, n - 1) {
    ll tmp; cin >> tmp;
    if(!ok) continue;

    if(tmp == 0) {
      prev = tmp;
      continue;
    }

    ll diff = tmp - prev;
    if(diff > 1) {
      ok = 0;
      continue;
    }

    if(diff == 1) {
      ++ans;
    } else {
      ans += tmp;
    }

    prev = tmp;
  }

  if(ok) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
}
