#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

class BinaryIndexedTree {
 private:
  int n;
  vector<int64> xs;
 public:
  BinaryIndexedTree(int n) : n(n), xs(n) {}

  // Adds x to the i-th element.
  void Add(int i, int64 x) {
    int cur = i;
    while (cur < n) {
      xs[cur] += x;
      cur = cur | (cur + 1);
    }
  }

  // Returns a sum of a range [l r).
  int64 SumOfRange(int l, int r) {
    if (l >= r) return 0;
    if (l > 0) {
      return SumOfRange(0, r) - SumOfRange(0, l);
    }
    int64 s = 0;
    int i = r - 1;
    while (i >= 0) {
      s += xs[i];
      i = (i & (i + 1)) - 1;
    }
    return s;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  BinaryIndexedTree bit(n);
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }
  for (int i = 0; i < n; i++) {
    bit.Add(i, xs[i]);
  }
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int p, x;
      cin >> p >> x;
      bit.Add(p, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << bit.SumOfRange(l, r) << "\n";
    }
  }
}