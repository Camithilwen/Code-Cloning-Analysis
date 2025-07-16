#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = (ll)(n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define FORD(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

void solve() {
  ll N, A, B, dist = 0;
  cin >> N >> A >> B;
  vector<ll> X(N);
  REP(i, N) { cin >> X[i]; }
  sort(ALL(X));
  FOR(i, 0, N - 1 - 1) {
    if ((X[i + 1] - X[i]) * A < B) {
      dist += (X[i + 1] - X[i]) * A;
    } else {
      dist += B;
    }
  }
  cout << dist << endl;
}

signed main() {
  solve();

  return 0;
}