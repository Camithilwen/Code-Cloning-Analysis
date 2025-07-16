#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<int> to[MAXN];
vector<int> d1(MAXN, -1), d2(MAXN, -1);

void dfs(int u, int path, vector<int> &d)
{
  if (d[u] != -1)
  {
    return;
  }
  d[u] = path;
  for (auto v : to[u])
  {
    dfs(v, path + 1, d);
  }
}

int main()
{
  int N, u, v, a, b;
  cin >> N >> u >> v;
  u--, v--;
  for (int i = 0; i < N - 1; i++)
  {
    cin >> a >> b;
    a--, b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  dfs(u, 0, d1);
  dfs(v, 0, d2);
  int ans = 0, same = (1 << 30);
  for (int i = 0; i < N; i++)
  {
    if (d2[i] < d1[i])
      continue;
    if (d2[i] == d1[i])
    {
      same = min(d2[i], same);
    }
    else
    {
      ans = max(ans, d2[i] - 1);
    }
  }
  if (ans == 0 && same != (1 << 30))
  {
    cout << same << endl;
  }
  else
  {
    cout << ans << endl;
  }
}
