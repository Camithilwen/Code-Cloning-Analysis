#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int cnt = 0;
  while (1) {
    rep(i, n) {
      if (a[i] % 2 != 0) {
        cout << cnt << endl;
        return 0;
      }
      a[i] *= 0.5;
    }
    cnt++;
  }

  return 0;
}