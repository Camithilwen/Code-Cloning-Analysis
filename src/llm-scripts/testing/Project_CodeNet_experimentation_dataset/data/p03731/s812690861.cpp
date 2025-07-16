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

const int inf = INT_MAX;
const int MOD = 1000000007;
const long long INF = LLONG_MAX;

// -------------------------------------------------------

ll N, T;
vector<Pll> ev;

int main() {
  cin >> N >> T;
  rep(i, 0, N) {
    ll t;
    cin >> t;
    ev.push_back(Pll(t, 1));
    ev.push_back(Pll(t + T, 0));
  }

  sort(ev.begin(), ev.end());

  ll st = 0;
  ll end = T;
  ll ans = 0;
  for (auto e : ev) {
    if (e.second == 1) {
      if (e.first <= end) {
        end = e.first + T;
      } else {
        ans += end - st;
        st = e.first;
        end = e.first + T;
      }
    } else {
      if (e.first <= end) {
        continue;
      } else {
        ans += end - st;
        st = -1;
        end = -1;
      }
    }
  }

  ans += end - st;

  cout << ans;
}
