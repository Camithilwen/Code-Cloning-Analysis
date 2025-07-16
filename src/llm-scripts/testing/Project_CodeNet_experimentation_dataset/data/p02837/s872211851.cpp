#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using lpair = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

constexpr llong mod = 1e9+7;
constexpr llong inf = mod * mod;

int main() {
  llong N;
  vector<vector<lpair>> A;

  cin >> N;
  A.resize(N + 1);
  for (int i = 1; i <= N; i++) {
    llong n;
    cin >> n;
    A[i].resize(n);
    for (auto &in: A[i]) {
      cin >> in.first >> in.second;
    }
  }

  int ans = 0;
  for (int i = 0; i < (1<<N); i++) {
    vector<int> res(N + 1);
    for (int j = 0; j < N; j++) {
      res[j + 1] = (i>>j)&1;
    }

    bool check = true;
    for (int j = 0; j < N; j++) {
      if (!((i>>j)&1)) continue;
      for (auto a: A[j + 1]) {
        check &= res[a.first] == a.second;
      }
    }

    if (check) {
      ans = max(ans, __builtin_popcount(i));
    }
  }

  cout << ans << endl;

  return 0;
}