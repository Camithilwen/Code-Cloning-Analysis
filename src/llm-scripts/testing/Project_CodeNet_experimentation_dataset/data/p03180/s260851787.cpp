#include <bits/stdc++.h>
using namespace std; inline void fileio(const char* in, const char* out) { freopen(in, "r", stdin); freopen(out, "w", stdout); }
#define TD typedef
#define forx(i,n) for(int i = 0; i < (n); ++i)
#define forxr(i,n) for(int i = (n)-1; i >= 0; --i)
TD long long ll; TD long double ld; TD pair<int,int> pii; TD pair<ll,ll> pll; TD vector<int> VI; TD vector<bool> VB; TD vector<ll> VL;
const char nl = '\n'; const int INF = 0x3f3f3f3f; const ll LINF = 0x3f3f3f3f3f3f3f3fll; const ld EPS = 1e-9, PI = acos(-1);
#define ff first
#define ss second
#define all(c) c.begin(),c.end()

const int N = 17;
int a[N][N], n;
struct bm {
  int v; bm(int val=0) : v(val) {}
  bool operator[](int i) const { return v & 1 << i; }
  bm set(int i) const { return bm(v | 1 << i); }
  bm invert() const { return bm(v ^ -1); }
};
#define for_submasks(s, m) for (int s=m, l=1<<__builtin_popcount(m); l--; s=(s-1)&m)

ll dp[1 << N];
ll s[1<<N];

ll score(bm mask) {
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (mask[i] && mask[j]) {
        ans += a[i][j];
      }
    }
  }
  return ans;
}
void pre() {
  for (int i = 0; i < (1 << n); ++i) {
    s[i] = score(i);
  }
}

int main() { // Emily <3
  atexit([](){ cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << nl; });
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cout << fixed << setprecision(12);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  pre();
  memset(dp, -INF, sizeof dp);
  dp[0] = 0;
  for (int mask = 0; mask < (1<<n); ++mask) {
    for_submasks(sm, mask) {
      if (sm == mask) continue;
      dp[mask] = max(dp[mask], dp[sm] + s[mask ^ sm]);
    }
  }
  cout << dp[(1 << n)-1] << nl;

  return 0;
}

