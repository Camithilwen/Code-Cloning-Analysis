#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  deque<int> r;
  rep(i, n) {
    int idx = lower_bound(r.begin(), r.end(), a[i]) - r.begin();
    --idx;
    if (idx < 0) {
      r.push_front(a[i]);
    } else {
      r[idx] = a[i];
    }
  }

  cout << r.size() << endl;
  return 0;
}
