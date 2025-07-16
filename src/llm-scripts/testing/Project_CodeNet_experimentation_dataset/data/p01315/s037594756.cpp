#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using pii = pair<int, int>;
using vi = vector<int>;
using lint = long long;

const int inf = 1001001001;
const lint linf = 1001001001001001001ll;
const int mod = 1e9 + 7;
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1}, dy[]{1, 0, -1, 0, -1, 1, -1, 1};

template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; } return a > b; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; } return a < b; }
template<typename T> inline void print(const T &x, string s = "\n") { cout << x << s; }
template<typename T> inline void print(const vector<T> &v, string s = " ")
{ if (!v.size()) puts(""); rep(i, v.size()) cout << v[i] << (i + 1 == v.size() ? "\n" : s); }
inline bool inside(int y, int x, int H, int W) { return 0 <= y && y < H && 0 <= x && x < W; }
inline lint in() { lint x; std::cin>>x; return x; }

bool izryt(pair<pair<int, int>, string> a, pair<pair<int, int>, string> b) {
  if (a.fs.fs * b.fs.sc == b.fs.fs * a.fs.sc) return a.sc < b.sc;
  return a.fs.fs * b.fs.sc > b.fs.fs * a.fs.sc;
}
signed main() {
  int n;

  while (cin >> n, n) {
    vector<pair<pair<int, int>, string>> v;

    rep(i, n) {
      string l;
      cin >> l;

      int p = in();
      int u = 0, t = 0;

      rep(i, 3) u += in();
      rep(i, 2) t += in();

      int f = in();
      int s = in();
      int m = in();

      v.pb(mp(mp((f * m * s - p), (u + t * m)), l));
    }
    sort(all(v), izryt);

    rep(i, n) {
      cout << v[i].sc << endl;
    }
    cout << "#" << endl;
  }
}