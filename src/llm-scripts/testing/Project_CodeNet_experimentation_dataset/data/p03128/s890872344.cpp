#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const int need[10] = {0, 2,5,5,4,5,6,3,7,6};
const int N = 10005;
string dp[N];
void chmax (string& s, string t) {
  if ((int) s.size() < (int) t.size()) s = t;
  else if ((int) s.size() < (int) t.size()) return;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] != t[i]) {
      if (t[i] > s[i]) {
        s = t;
        return;
      } else {
        return;
      }
    }
  }
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  //string test = "74";
  //chmax(test, "47");
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++) cin >> a[i];
  dp[0] = "";
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      if (i + need[a[j]] <= n && (i == 0 || dp[i] != "")) {
        chmax(dp[i + need[a[j]]], dp[i] + (char) (a[j] + '0'));
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}