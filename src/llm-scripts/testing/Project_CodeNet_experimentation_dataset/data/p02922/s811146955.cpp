// time-limit: 2000
// 23
#include <bits/stdc++.h>
using namespace std;
#define coutc "\033[48;5;196m\033[38;5;15m"
#define endc "\033[0m"
#define endl '\n'
#define M(_1, _2, _3, _4, NAME, ...) NAME
#define rep(...) \
  M(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rep4(_, x, n, s) \
  for (int _ = x; (s < 0) ? _ > n : _ < n; _ += s)
#define rep3(_, x, n) rep4(_, x, n, (x < n ? 1 : -1))
#define rep2(_, n) rep3(_, 0, n)
#define rep1(n) rep2(i, n)
#define fi first
#define se second
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define len(x) int(x.size())
#define lli __int128_t
#define li long long int
#define ld long double
#ifdef DEBUG
// 3
ostream &operator<<(ostream &o, pair<auto, auto> p) {
  return o << "(" << p.fi << ", " << p.se << ")";
}
// 4
ostream &operator<<(ostream &o, vector<auto> v) {
  rep(i, len(v)) o << setw(7) << right << v[i];
  return o << endc << endl << coutc;
}
// 4
ostream &operator<<(ostream &o, map<auto, auto> m) {
  for (auto &kv : m) o << kv;
  return o;
}
// 7
void debug(const auto &e, const auto &... r) {
  cout << coutc << e;
  ((cout << " " << r), ..., (cout << endc << endl));
}
#else
#define debug(...)
#endif

int sign(li x) { return x < 0 ? -1 : x > 0; }

//         a / b
li ceil(li a, li b) {
  if (sign(a) == sign(b) && a % b) return a / b + 1;
  else return a / b;
}

void _main(int tc) {
    int a, b;
    cin >> a >> b;

    // b = a + (a - 1) * X
    // X = (b - a) / (a - 1)
    // is ceiling because we need to assure that with X pipes we complete "b - a" lines.
    // we add one because after fullfilling "b - a" we still need to complete with "a" lines.
    cout << ceil(b - a, a - 1) + 1 << endl;
}
// 7
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0), exit(0);
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}
