#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

ll N, x;
ll a[101010];

int main() {
  cin >> N >> x;
  rep(i, 0, N) { cin >> a[i]; }

  ll ans = max(0LL, a[0] - x);
  a[0] -= ans;
  ll prev = a[0];
  rep(i, 1, N) {
    ll diff = max(0LL, prev + a[i] - x);
    ans += diff;
    a[i] -= diff;
    prev = a[i];
  }

  cout << ans << endl;
}
