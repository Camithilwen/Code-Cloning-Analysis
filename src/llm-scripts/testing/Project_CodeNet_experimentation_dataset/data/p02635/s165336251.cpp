#include <bits/stdc++.h>
using namespace std;
const int N = 305, M = 998244353;
int dp[N][N][N];
vector<int> a;
int k;

int solve(int x, int cur, int rem) {
  if (cur > k || rem < 0) return 0;
  if (x == -1) return (rem == 0);

  int &ret = dp[x][cur][rem];
  if (~ret) return ret;
  ret = 0;

  for (int i = 0; i <= a[x]; ++i) {
    ret = (ret + solve(x - 1, cur + i, rem + i)) % M;
  }
  for (int i = 1; i <= rem; ++i) {
    ret = (ret + solve(x - 1, cur, rem - i)) % M;
  }
  return ret;
}


int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string s;
  cin >> s >> k;

  memset(dp, -1, sizeof dp);
  a.push_back(0);
  for (auto i : s) {
    if (i == '0') a.push_back(0);
    else a.back()++;
  }

  cout << solve((int)a.size() - 1, 0, 0) << '\n';
}
