#include <bits/stdc++.h>
using namespace std;

// #define int ll
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define mp        make_pair
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second

int inf(0x3fffffff);
int mod(998244353);
double pi(acos(-1.0));

ll iv(ll a, ll b) {
  return a > 1 ? b - iv(b % a, a) * b / a : 1;
}

ll modExp(ll b, ll e) {
  ll r = 1;
  while (e) {
    if (e & 1) r = r * b % mod;
    b = b * b % mod;
    e /= 2;
  }
  return r;
}

vector<ll> dpc;

ll C(int n, int r) {
  if (dpc.empty()) {
    dpc.pb(1);
    for (int i = 1; i <= n; i++) {
      dpc.pb(dpc[i - 1] * (n - i + 1) % mod * iv(i, mod) % mod);
    }
  }
  return dpc[r];
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  int n, m, k;
  cin >> n >> m >> k;

  ll cnt = 0;
  rep(i, k + 1) {
    cnt = (cnt + m * modExp(m - 1, n - i - 1) % mod *
           C(n - 1, i)) % mod;
  }

  cout << cnt;


  return 0;
}
