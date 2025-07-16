#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 1e12

#define PB push_back
#define PF push_front
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vpi vector<pii>
#define vll vector<ll>
#define vpl vector<pll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pr_d(x) cout << fixed << setprecision(15) << x << endl
#define ud(c, x) distance(c.begin(), upper_bound(all(c), x))
#define ld(c, x) distance(c.begin(), lower_bound(all(c), x))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define rep3(i, n) for (int i = (n - 1); i >= 0; --i)
#define rep4(i, a, b) for (int i = (a); i > (b); --i)
#define pb push_back
#define out(x) cout << x << "\n"
bool odd(int i) { return i % 2; }

#define all(v) v.begin(), v.end()
#define size(x) int(x.size())

int gcd(int a, int b) { return __gcd(a, b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
void Yes_No(bool f) {
  if (f)
    printf("Yes\n");
  else
    printf("No\n");
}

void deb_p(pii p) { printf("pair = %d %d\n", p.fi, p.se); }
void deb_i(int i) { printf("i = %d\n", i); }
void deb_v(vector<int> v) {
  printf("v = ");
  for (auto i : v) printf("%d ", i);
  printf("\n");
}
template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
//-------------------ここから回答する-----------------------

void solve(void) {
  int n, x;
  cin >> n >> x;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> sum(n - 1);
  rep(i, n - 1) sum[i] = a[i] + a[i + 1];
  ll ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (sum[i] <= x)
      continue;
    else {
      int d = min(a[i + 1], sum[i] - x);
      ans += d;
      sum[i] -= d;
      sum[i + 1] -= d;
    }
  }
  if (sum[0] > x) {
    int d = sum[0] - x;
    sum[0] -= d;
    ans += d;
  }
  if (sum[n - 2] > x) {
    int d = sum[n - 2] - x;
    sum[n - 2] -= d;
    ans += d;
  }
  cout << ans << endl;
}
int main(void) { solve(); }