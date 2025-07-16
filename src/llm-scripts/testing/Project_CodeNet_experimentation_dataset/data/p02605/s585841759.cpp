#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1e8;

// URDL = 0123

int f(vector<P> a) {
  sort(a.begin(), a.end());
  int res = INF;
  for (int i = 1; i < a.size(); ++i) {
    if (a[i-1].second == 0 && a[i].second != 0) {
      res = min(res, a[i].first-a[i-1].first);
    }
  }
  return res;
}
int f(map<int,vector<P>>& mp) {
  int res = INF;
  for (auto p : mp) {
    res = min(res, f(p.second));
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n), dir(n);
  rep(i,n) {
    char c;
    cin >> x[i] >> y[i] >> c;
    if (c == 'U') dir[i] = 0;
    if (c == 'R') dir[i] = 1;
    if (c == 'D') dir[i] = 2;
    if (c == 'L') dir[i] = 3;
  }

  int ans = INF;
  rep(ri,4) {
    { // UD
      map<int,vector<P>> mp;
      rep(i,n) {
        if (dir[i] != 0 && dir[i] != 2) continue;
        mp[x[i]].emplace_back(y[i],dir[i]);
      }
      ans = min(ans, f(mp)*5);
    }
    { // UR
      map<int,vector<P>> mp;
      rep(i,n) {
        if (dir[i] != 0 && dir[i] != 1) continue;
        mp[x[i]+y[i]].emplace_back(y[i],dir[i]);
      }
      ans = min(ans, f(mp)*10);
    }
    // rotate
    rep(i,n) {
      int px = x[i], py = y[i];
      x[i] = py;
      y[i] = -px;
      dir[i] = (dir[i]+1)%4;
    }
  }
  if (ans == INF) cout << "SAFE" << endl;
  else cout << ans << endl;
  return 0;
}