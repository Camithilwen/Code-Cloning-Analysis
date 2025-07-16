#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <time.h>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < n; i++)
#define all(c) (c).begin(), (c).end()
#define P pair<int, int>
#define chmin(x, y) x = min(x, y)

int main()
{
  string s;
  cin >> s;
  reverse(all(s));
  s += '0';

  int n = s.size();

  const int INF = 100100100;
  vector<vector<int>> dp(n + 1, vector<int>(2, INF));
  dp[0][0] = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      int x = s[i] - '0';
      x += j;
      if (x < 10)
        chmin(dp[i + 1][0], dp[i][j] + x);
      if (x > 0)
        chmin(dp[i + 1][1], dp[i][j] + (10 - x));
    }
  }

  cout << dp[n][0] << endl;
}
