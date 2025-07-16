#include <bits/stdc++.h>
using namespace std;
double solve(vector<vector<vector<double>>> &dp,int a, int b, int c, int n) {
  if (dp[a][b][c]) return dp[a][b][c];
  if (!a&&!b&&!c) return 0;
  dp[a][b][c] = 1.0*n/(a+b+c);
  if (a) dp[a][b][c] += solve(dp,a-1,b,c,n)*a/(a+b+c);
  if (b) dp[a][b][c] += solve(dp,a+1,b-1,c,n)*b/(a+b+c);
  if (c) dp[a][b][c] += solve(dp,a,b+1,c-1,n)*c/(a+b+c);
  return dp[a][b][c];
}
int main() {
  int N;
  cin >> N;
  int ones = 0, twos = 0, threes = 0, a;
  vector<vector<vector<double>>> dp(N+1,vector<vector<double>>(N+1,vector<double>(N+1)));
  for (int i = 0; i < N; i++) {
    cin >> a;
    ones += a == 1;
    twos += a == 2;
    threes += a == 3;
  }
  cout.precision(20);
  cout << solve(dp,ones,twos,threes,N);
}