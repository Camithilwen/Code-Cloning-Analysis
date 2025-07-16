#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
#define chmax(x, v)                                                            \
  do {                                                                         \
    x = max(x, v);                                                             \
  } while (0)
#define chmin(x, v)                                                            \
  do {                                                                         \
    x = min(x, v);                                                             \
  } while (0)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

// {{{ (k)MP: Search pattern from text
// MP<std::string> mp("a");
// auto res = mp.findAll("aabb"); // res = {0, 1}
template<typename T>
class MP {
  private:
    ll n;
    T t;
    std::vector<ll> a;
  public:
    explicit constexpr MP(const T &pattern) : t(pattern) {
      n = pattern.size();
      a = std::vector<ll>(n+1);
      a[0] = -1;
      int j = -1;
      for (int i = 0; i < n; ++i) {
        while (j != -1 && pattern[j] != pattern[i])
          j = a[j];
        j++;
        a[i+1] = j;
      }
    }
    ll operator[](ll i) {
      return a[i];
    }
    std::vector<ll> findAll(const T &text) {
      std::vector<ll> res;
      int j = 0;
      for (int i = 0; i < text.size(); ++i) {
        while (j != -1 && t[j] != text[i])
          j = a[j];
        j++;
        if (j == n) {
          res.push_back(i-j+1);
          j = a[j];
        }
      }
      return res;
    }
};
// }}}

ll N;
vector<ull> a, b;

vector<ull> diff(vector<ull> &v) {
  vector<ull> res(v.size());
  rep(i, N) {
    res[i] = v[i] ^ v[(i+1)%N];
  }
  return res; 
}

signed main() {
  cin >> N;
  a.resize(N);
  b.resize(N);
  rep(i, N) { cin >> a[i]; }
  rep(i, N) { cin >> b[i]; }
  auto ad = diff(a);
  auto bd = diff(b);

  bd.insert(bd.end(), bd.begin(), bd.end()); // bd += bd;

  // cout << "diff: " << endl;
  // for (auto x : ad) { cout << x << " "; } cout << endl;
  // for (auto x : bd) { cout << x << " "; } cout << endl;

  MP<vector<ull>> mp(ad);
  auto matches = mp.findAll(bd);
  reverse(begin(matches), end(matches));
  for (auto i : matches) {
    ll k = N-i;
    if (k >= N)
      continue;
    ull x = a[k] ^ b[0];
    cout << k << " " << x << endl;
  }
  return 0;
}
