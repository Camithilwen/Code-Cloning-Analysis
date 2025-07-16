#include <bits/stdc++.h>
using namespace std;
int N, T;
int64_t DP[3010][3010]; // i番目、t分後の最大値

void init()
{
  for (int i = 0; i < 3010; i++)
    for (int j = 0; j < 3010; j++)
      DP[i][j] = -1;
  DP[0][0] = 0;
}

int64_t ans()
{
  int64_t ans = 0;
  for (int j = 0; j <= T; j++)
    ans = max(DP[N][j], ans);
  return ans;
}

int main()
{
  cin >> N >> T;
  vector<pair<int, int>> ab(N);
  for (int i = 0; i < N; i++)
  {
    cin >> ab[i].first >> ab[i].second;
  }
  sort(ab.begin(), ab.end());
  for (int i = 0; i < N; i++)
  {
    for (int t = 0; t <= T; t++)
    {
      if (DP[i][t] == -1)
        continue;
      DP[i + 1][t] = max(DP[i + 1][t], DP[i][t]);
      if (t < T)
      {
        DP[i + 1][min(t + ab[i].first, T)] = max(DP[i + 1][min(t + ab[i].first, T)], DP[i][t] + ab[i].second);
      }
    }
  }
  cout << ans() << endl;
}