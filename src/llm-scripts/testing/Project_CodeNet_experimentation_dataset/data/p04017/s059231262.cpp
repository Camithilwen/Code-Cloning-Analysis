#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

constexpr int NUM_BITS = 18;

template<typename T>
vector<vector<T>> Make2DVector(int d1, int d2, T default_value) {
  return vector<vector<T>>(d1, vector<T>(d2, default_value));
}

// Returns a tuple of (l, u) s.t.
// - l is the minimum value s.t. is_upper_fn(l) is false.
// - r is the minimum value s.t. is_upper_fn(r) is true.
//
// Required:
// - is_upper_fn is a function s.t.
//   - There exists a constant c s.t. is_upper_fn(x) is true for x >= c and
//     is_upper_fn(x) is false for x < c.
// - is_upper_fn(min_value) is false.
// - is_upper_fn(max_value) is true.
//
// Verified: ABC144E
tuple<int64, int64> BinarySearch(function<bool(int64)> is_upper_fn, int64 l, int64 u) {
  while (u - l >= 2) {
    int64 m = (l + u) / 2;
    if (is_upper_fn(m)) u = m; else l = m;
  }
  return make_tuple(l, u);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }
  int64 c;
  cin >> c;

  auto next_table = Make2DVector(NUM_BITS, n, -1);
  for (int i = 0; i < n; i++) {
    next_table[0][i] = i;
    if (i > 0) next_table[0][i] = next_table[0][i - 1];
    while (next_table[0][i] + 1 < n && xs[next_table[0][i] + 1] - xs[i] <= c) {
      next_table[0][i]++;
    }
  }

  for (int b = 1; b < NUM_BITS; b++) {
    for (int i = 0; i < n; i++) {
      next_table[b][i] = next_table[b - 1][next_table[b - 1][i]];
    }
  }

  int q_count;
  cin >> q_count;
  for (int q = 0; q < q_count; q++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a > b) swap(a, b);

    auto is_upper_fn = [&](int k) -> bool {
      int v = a;
      for (int b = 0; b < NUM_BITS; b++) {
        if (k & (1 << b)) {
          v = next_table[b][v];
        }
      }
      return v >= b;
    };

    int l = 0;
    int u = n - 1;
    tie(l, u) = BinarySearch(is_upper_fn, l, u);
    cout << u << "\n";
  }
}