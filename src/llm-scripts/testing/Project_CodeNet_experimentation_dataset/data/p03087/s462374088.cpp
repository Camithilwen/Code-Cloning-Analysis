#define _DEBUG 1
#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#ifdef _DEBUG
#define dump(x) cerr << #x << "=" << x << endl
#define dump2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define dump3(x, y, z)                                                     \
  cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z \
       << endl
#define check(s) cerr << s << endl
#else
#define dump(x)
#define dump2(x, y)
#define dump3(x, y, z)
#define check(s)
#endif

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

const ll LINF = 2e18;
const int INF = 1e9;

void solve(ll N, ll Q, std::string S, std::vector<ll> l, std::vector<ll> r) {
  vector<ll> a(N, 0);
  FOR(i, 1, N) {
    a.at(i) = a.at(i - 1);
    if (S.at(i) == 'C' && S.at(i - 1) == 'A') a.at(i) += 1;
  }

  rep(i, Q) cout << a.at(r.at(i) - 1) - a.at(l.at(i) - 1) << endl;
}

int main() {
  ll N;
  scanf("%lld", &N);
  ll Q;
  scanf("%lld", &Q);
  std::string S;
  std::cin >> S;
  std::vector<ll> l(Q);
  std::vector<ll> r(Q);
  for (int i = 0; i < Q; i++) {
    scanf("%lld", &l[i]);
    scanf("%lld", &r[i]);
  }
  solve(N, Q, S, std::move(l), std::move(r));
  return 0;
}
