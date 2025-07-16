//\\//\\ * * * //\\// ||
#include <bits/stdc++.h> 

#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;
  
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
  
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
 
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, tt;
  cin >> n >> tt;
  fenwick<ll> fenw(n);
  auto Get = [&](int l, int r) {
    return (l == 0 ? fenw.get(r) : fenw.get(r) - fenw.get(l - 1));
  };
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    fenw.modify(i, x);
  }
  while (tt--) {
    int q;
    cin >> q;
    if (q == 1) {
      int l, r;
      cin >> l >> r;
      cout << Get(l, r - 1) << '\n';
    } else {
      int p;
      cin >> p;
      ll x;
      cin >> x;
      fenw.modify(p, x);
    }
  }
  return 0;
}
