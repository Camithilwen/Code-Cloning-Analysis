#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

ll f[1000000], finv[1000000];

ll modpow(ll a,ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll modinv(ll a) {
  return modpow(a, mod - 2);
}

void init() {
  f[0] = 1, finv[0] = 1;
  FOR(i, 1, 1000000) {
    f[i] = f[i - 1] * i % mod;
    finv[i] = modinv(f[i]);
  }
}

ll comb(ll n, ll r) {
  if (r < 0 || r > n) return 0;
  return f[n] * finv[r] % mod * finv[n - r] % mod;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  init();
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  rep(i, n - 1) {
    if (a[i] == a[i + 1]) {
      cout << 0 << '\n';
      return 0;
    }
  }
  rep(i, m - 1) {
    if (b[i] == b[i + 1]) {
      cout << 0 << '\n';
      return 0;
    }
  }
  ll ans = 1, idxa = 0, idxb = 0, cnt = 0;
  while (idxa < n && idxb < m && ans > 0) {
    if (a[idxa] < b[idxb]) {
      ans = ans * comb(a[idxa] - 1 - cnt, m - idxb - 1) % mod * f[m - idxb] % mod;
      cnt += m - idxb;
      idxa++;
    }
    else if (a[idxa] > b[idxb]) {
      ans = ans * comb(b[idxb] - 1 - cnt, n - idxa - 1) % mod * f[n - idxa] % mod;
      cnt += n - idxa;
      idxb++;
    }
    else {
      ans = ans * comb(a[idxa] - 1 - cnt, n - idxa - 1 + m - idxb - 1) % mod * f[m - idxb - 1 + n - idxa - 1] % mod;
      cnt += n - idxa + m - idxb - 1;
      idxa++, idxb++;
    }
  }
  cout << ans << '\n';


  
  return 0;
}