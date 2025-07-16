#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  rep(i, n) cin >> a.at(i + 1);
  vector<int> b(n + 1, 0);
  for (int i = n; i >= 1; i--) {
    int sum = 0;
    for (int j = i + i; j <= n; j += i) {
      sum += b.at(j);
    }
    if (a.at(i) == 1) {
      if (sum % 2 == 1) {
        b.at(i) = 0;
      } else {
        b.at(i) = 1;
      }
    } else {
      if (sum % 2 == 1) {
        b.at(i) = 1;
      } else {
        b.at(i) = 0;
      }
    }
  }
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    if (b.at(i) == 1) {
      res.push_back(i);
    }
  }
  cout << res.size() << endl;
  rep(i, res.size()) {
    if (i != 0) {
      cout << " ";
    }
    cout << res.at(i);
  }
  cout << endl;
  return 0;
}
