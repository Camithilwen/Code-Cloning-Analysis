#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int c[500005];
int d[500005];
int e[500005];
int a[500005];
int bit[500005];
vector<pair<int, int>> v[500005];
int n, q;
// 1 is true
// 0 is false

int esum(int l, int r) {
  int sum = 0;
  for (int i = l; i <= r; i++) {
    sum += e[i];
  }
  return sum;
}

void update(int i, int value) {
  for (; i <= n; i += i & -i) {
    bit[i] += value;
  }
}

int sum(int i) {
  int s = 0;
  for (; i > 0; i -= i & -i) {
    s += bit[i];
  }
  return s;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    v[r].push_back({i, l});
  }

  for (int i = 1; i <= n; i++) {
    if (d[c[i]] != 0) {
      update(d[c[i]], -1);
    }
    d[c[i]] = i;
    update(i, 1);
    for (auto x : v[i]) {
      a[x.first] = sum(i) - sum(x.second - 1);
    }
    // for (int r = 1; r <= n; r++) {
    //   cout << c[r] << ' ';
    // }
    // cout << endl;
    // for (int r = 1; r <= n; r++) {
    //   cout << d[r] << ' ';
    // }
    // cout << endl;
    // for (int r = 1; r <= n; r++) {
    //   cout << e[r] << ' ';
    // }
    // cout << endl << "--------------------------------" << endl;
  }
  for (int i = 1; i <= q; i++) {
    cout << a[i] << endl;
  }
}
