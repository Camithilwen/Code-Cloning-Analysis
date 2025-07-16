#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

class U {
public:
  int n;
  vector<int> p, s;
  U(int _) {
    n = _;
    p.resize(n);
    s.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      s[i] = 1;
    }
  }
  bool connect(int a, int b) {
    int ap, bp;
    for (ap = p[a]; ap != p[ap]; ap = p[ap])
      ;
    for (bp = p[b]; bp != p[bp]; bp = p[bp])
      ;
    if (ap == bp)
      return true;
    int mi = min(ap, bp), ma = max(ap, bp);
    p[ma] = mi;
    s[mi] += s[ma];
    s[ma] = 0;
    for (int pp = a; pp != mi;) {
      int next = p[pp];
      p[pp] = mi;
      pp = next;
    }
    for (int pp = b; pp != mi;) {
      int next = p[pp];
      p[pp] = mi;
      pp = next;
    }
    return false;
  }
  int q(int a) {
    int ap;
    for (ap = a; ap != p[ap]; ap = p[ap])
      ;
    return s[ap];
  }
  int parent(int a) {
    int ap;
    for (ap = a; ap != p[ap]; ap = p[ap])
      ;
    return p[ap];
  }
  bool query(int a, int b) { return parent(a) == parent(b); }
};

template <typename T> class RMQ {
  vector<T> data;
  T unit;

public:
  static const long long INF = 100000000000;
  int n;
  function<T(const T &, const T &)> f;
  RMQ(int _, T u, function<T(T, T)> bi) {
    unit = u;
    f = bi;
    n = 1;
    while (n < _) {
      n <<= 1;
    }
    data.resize(n * 4);
    for (int i = 0; i < n * 4; i++)
      data[i] = unit;
  }
  void update(int index, T val) {
    int i = index + n - 1;
    data[i] = val;
    while (i > 0) {
      i = (i - 1) / 2;
      data[i] = f(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }
  // [a, b)
  T query(int a, int b, int k, int l, int r) {
    if (a < 0 || r <= a || b <= l)
      return unit;
    if (a <= l && r <= b)
      return data[k];
    else
      return f(query(a, b, k * 2 + 1, l, (l + r) / 2),
               query(a, b, k * 2 + 2, (r + l) / 2, r));
  }
  T query(int a, int b) { return query(a, b, 0, 0, n); }
};

struct N {
  int i, j;
  long long c;
};
bool operator<(const N &l, const N &r) { return l.c < r.c; }

ll INF = 1000000000000000000LL;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  ll d;
  cin >> n >> d;
  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  map<ll, vi> mp;
  for (int i = 0; i < n; i++)
    mp[a[i]].push_back(i);
  auto f = [](const pair<ll, int> &l, const pair<ll, int> &r) {
    if (l.first < r.first)
      return l;
    else
      return r;
  };
  pair<ll, int> unit = make_pair(INF, -1);
  RMQ<pair<ll, int>> l(n + 2, unit, f), r(n + 2, unit, f);
  U u(n);
  vector<N> paths;
  for (auto &v : mp) {
    for (auto &i : v.second) {
      auto lp = l.query(0, i);
      auto rp = r.query(i, n);

      if (lp.second >= 0) {
        paths.push_back(
            N{i, lp.second, abs(i - lp.second) * d + a[i] + a[lp.second]});
      }
      if (rp.second >= 0) {
        paths.push_back(
            N{i, rp.second, abs(i - rp.second) * d + a[i] + a[rp.second]});
      }
      l.update(i, make_pair(a[i] + (n - i) * d, i));
      r.update(i, make_pair(a[i] + i * d, i));
    }
  }

  sort(paths.begin(), paths.end());
  ll ans = 0;
  for (auto &p : paths) {
    if (!u.connect(p.i, p.j)) {
      ans += p.c;
    }
  }
  cout << ans << endl;
  return 0;
}
