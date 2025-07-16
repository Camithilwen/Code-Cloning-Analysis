#include <bits/stdc++.h>

using namespace std;

string S;
int K;
int dp[300][300][300];

int rec(int left, int right, int rest) {
  if(left >= right) return left == right;
  if(~dp[left][right][rest]) return dp[left][right][rest];
  int ret = max(rec(left + 1, right, rest), rec(left, right - 1, rest));
  if(rest > 0) ret = max(ret, rec(left + 1, right - 1, rest - 1) + 2);
  if(S[left] == S[right]) ret = max(ret, rec(left + 1, right - 1, rest) + 2);
  return dp[left][right][rest] = ret;
}

int main() {
  cin >> S >> K;
  memset(dp, -1, sizeof(dp));
  cout << rec(0, S.size() - 1, K) << endl;
}