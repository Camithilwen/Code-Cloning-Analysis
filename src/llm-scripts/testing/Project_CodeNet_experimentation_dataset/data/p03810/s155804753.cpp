#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

bool Solve(int n, const vector<int>& xs) {
  if (n == 1) {
    return false;
  }

  int even_count = 0;
  for (int x : xs) {
    if (x % 2 == 0) even_count++;
  }

  if (n % 2 == 0) {
    return even_count % 2 == 1;
  } else {
    if (even_count <= n - 2) {
      return even_count % 2 == 1;
    } else {
      vector<int> ys(n);
      for (int i = 0; i < n; i++) {
        if (xs[i] % 2 == 1) {
          if (xs[i] == 1) return false;
          ys[i] = xs[i] - 1;
        } else {
          ys[i] = xs[i];
        }
      }
      int d = ys[0];
      for (int i = 1; i < n; i++) {
        d = gcd(ys[i], d);
      }
      for (int i = 0; i < n; i++) {
        ys[i] /= d;
      }
      return !Solve(n, ys);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  bool ans = Solve(n, xs);
  if (ans) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
}