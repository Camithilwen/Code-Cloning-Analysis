// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define forever for (;;)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
template<typename A> using V = std::vector<A>;
template<typename A> using F = std::function<A>;
template<typename A, typename B> using P = std::pair<A, B>;
using pii = P<int, int>;
using vi = V<int>;
using vd = V<double>;
using vs = V<std::string>;
using vpii = V<pii>;
using vvi = V<vi>;
using vvpii = V<vpii>;
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979;
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
constexpr bool odd(const int n) { return n & 1; }
constexpr bool even(const int n) { return ~n & 1; }
template<typename T> std::istream &operator>>(std::istream &is, std::vector<T> &v) { for (T &x : v) is >> x; return is; }
template<typename A, typename B> std::istream &operator>>(std::istream &is, std::pair<A, B> &p) { is >> p.first; is >> p.second; return is; }
using namespace std;
// clang-format on

main {
  vi v(5);
  char gomi;
  while (cin >> v[0] >> gomi >> v[1] >> gomi >> v[2] >> gomi >> v[3] >> gomi >> v[4]) {
    sort(all(v));
    if (v[0] == v[3] || v[1] == v[4]) {
      cout << "four card" << endl;
      continue;
    }
    if ((v[0] == v[1] && v[2] == v[4]) || (v[0] == v[2] && v[3] == v[4])) {
      cout << "full house" << endl;
      continue;
    }
    if (v[4] - v[0] == 4 || (v[0] == 1 && v[1] == 10 && v[4] - v[1] == 3)) {
      cout << "straight" << endl;
      continue;
    }
    if (v[0] == v[2] || v[1] == v[3] || v[2] == v[4]) {
      cout << "three card" << endl;
      continue;
    }
    if ((v[0] == v[1] && (v[2] == v[3] || v[3] == v[4])) || (v[1] == v[2] && v[3] == v[4])) {
      cout << "two pair" << endl;
      continue;
    }
    if (v[0] == v[1] || v[1] == v[2] || v[2] == v[3] || v[3] == v[4]) {
      cout << "one pair" << endl;
      continue;
    }
    cout << "null" << endl;
  }
}