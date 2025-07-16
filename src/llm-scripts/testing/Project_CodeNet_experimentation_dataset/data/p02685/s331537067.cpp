
// Problem : E - Colorful Blocks
// Contest : AtCoder - AtCoder Beginner Contest 167
// URL : https://atcoder.jp/contests/abc167/tasks/abc167_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define int long long
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
#define db1(x) cout << #x << "=" << x << endl
#define db2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z)                                                       \
  cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z \
       << endl
#define dbp(x) \
  cout << #x << "= {" << (x.first) << ", " << (x.second) << "}" << endl;
#define dbv(v)                         \
  {                                    \
    cout << #v << " : ";               \
    for (auto x : v) cout << x << ' '; \
    cout << endl;                      \
  }
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rep2(i, a, b) for (int i = a; i >= b; i--)
#define die(x) return cout << x << '\n', 0;
const int MOD = 998244353;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int MAX = 2e5;
ll modulo(ll a, ll b, ll n) {
  ll x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % n;  // multiplying with base
    }
    y = (y * y) % n;  // squaring the base
    b /= 2;
  }
  return x % n;
}
vi fact(MAX + 1), factinv(MAX + 1);

void pre() {
  fact[0] = 1;
  factinv[0] = 1;
  for (int i = 1; i <= MAX; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
    factinv[i] = (factinv[i - 1] * modulo(i, MOD - 2, MOD)) % MOD;
  }
}

int mult(int a, int b) { return (a * b) % MOD; }
int nCr(int n, int r) {
  return mult(fact[n], mult(factinv[r], factinv[n - r]));
}

int32_t main() {
  fastio;
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
  int testcases;
  testcases = 1;
  // cin>>testcases;
  pre();
  while (testcases--) {
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    rep(i, 0, k) {
      int temp = nCr(n - 1, i);
      temp = mult(temp, m);
      temp = mult(temp, modulo(m - 1, n - 1 - i, MOD));
      ans = (ans + temp) % MOD;
    }
    cout << ans << '\n';
  }

  return 0;
}
