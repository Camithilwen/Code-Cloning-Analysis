#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1e8;

int cal(vector<P> A) {
  sort(A.begin(), A.end());
  int res = INF;
  for (int i = 1; i < sz(A); i++) {
    if (A[i-1].second == 0 && A[i].second != 0) {
      res = min(res, A[i].first - A[i-1].first);
    }
  }
  return res;
}

int F(map<int, vector<P>>& mp) {
  int res = INF;
  for (auto p : mp) {
    res = min(res, cal(p.second));
  }
  return res;
}

int main() {
  int N;
  cin >> N;
  vector<int> X(N), Y(N), dir(N);
  // URDL → 0123
  rep(i, N) {
    char c;
    cin >> X[i] >> Y[i] >> c;
    if (c == 'U') dir[i] = 0;
    if (c == 'R') dir[i] = 1;
    if (c == 'D') dir[i] = 2;
    if (c == 'L') dir[i] = 3;
  }
  int ans = INF;
  rep(_, 4) {
    { // UD
      map<int, vector<P>> mp;
      rep(i, N) {
        if (dir[i] != 0 && dir[i] != 2) continue;
        mp[X[i]].emplace_back(Y[i], dir[i]);
      }
      ans = min(ans, F(mp));
    }
    { // UR
      map<int, vector<P>> mp;
      rep(i, N) {
        if (dir[i] != 0 && dir[i] != 1) continue;
        mp[X[i]+Y[i]].emplace_back(Y[i], dir[i]);
      }
      ans = min(ans, F(mp) * 2);
    }
    {
      // rotate clockwise
      rep(i, N) {
        int px = X[i], py = Y[i];
        X[i] = py;
        Y[i] = -px;
        dir[i] = (dir[i]+1)%4;
      }
    }
  }
  if (ans < INF) cout << ans * 5 << '\n';
  else puts("SAFE");
  return 0;
}