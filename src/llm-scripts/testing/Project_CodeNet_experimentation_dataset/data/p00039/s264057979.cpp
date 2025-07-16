// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
// #define main int main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
#define stlice(from, to) substr(from, (to) - (from) + 1)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvpii = vector<vpii>;
template<typename A> using fn = function<A>;
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = acos(-1);
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
constexpr bool odd(const int &n) { return n & 1; }
constexpr bool even(const int &n) { return !odd(n); }
void solve();
main { solve(); return 0; }
// clang-format on

template<typename A>
using vpix = vector<pair<int, A>>;

vpix<char> u;
vpix<string> m;

int f(string s) {
  int c = 0, l = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    for (auto p : u) {
      if (s[i] == p.second) {
        c += p.first * (l <= p.first ? 1 : -1);
        l = p.first;
      }
    }
  }
  return c;
}

void solve() {
  u.pb(mp(1000, 'M'));
  u.pb(mp(500, 'D'));
  u.pb(mp(100, 'C'));
  u.pb(mp(50, 'L'));
  u.pb(mp(10, 'X'));
  u.pb(mp(5, 'V'));
  u.pb(mp(1, 'I'));
  string s;
  while (cin >> s) cout << f(s) << endl;
}