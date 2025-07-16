#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, M;
  vector<pair<int, int>> ans;
  cin >> N >> M;
  if (N % 2)
  {
    for (int l = 0, r = N - 1; l < r; l++, r--)
    {
      ans.emplace_back(l, r);
    }
  }
  else
  {
    bool flag = true;
    for (int l = 0, r = N - 1; l < r; l++, r--)
    {
      if (flag && r - l <= N / 2)
      {
        r--;
        flag = false;
      }
      ans.emplace_back(l, r);
    }
  }
  for (int i = 0; i < M; i++)
  {
    cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
  }
}