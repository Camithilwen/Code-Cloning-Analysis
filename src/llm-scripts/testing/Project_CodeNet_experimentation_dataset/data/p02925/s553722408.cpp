#include <bits/stdc++.h>
using namespace std;
int N;
const int MAXV = 1000005;
int A[1005][1005];
int ID[1005][1005];
vector<int> to[MAXV];

int toId(int i, int j)
{
  if (i > j)
  {
    swap(i, j);
  }
  return ID[i][j];
}

vector<int> dp(MAXV, -1);
vector<bool> visited(MAXV, 0);
int dfs(int u)
{
  if (visited[u])
  {
    return dp[u]; // 訪問済だが、dpが未決定の場合は閉路が存在
  }
  visited[u] = 1;
  int ret = 1;
  for (auto v : to[u])
  {
    int res = dfs(v);
    if (res == -1)
      return -1;
    ret = max(ret, res + 1);
  }
  return dp[u] = ret;
}

int main()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N - 1; j++)
    {
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  int V = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (i < j)
      {
        ID[i][j] = V++; // 各試合にノードのIDを割り当てる
      }
    }
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N - 1; j++)
    {
      A[i][j] = toId(i, A[i][j]); // i: 自分, j: 対戦相手, でIDに変換
    }
    for (int j = 1; j < N - 1; j++)
    {
      to[A[i][j]].push_back(A[i][j - 1]); // 入力のノード
    }
  }
  int ans = 0;
  for (int i = 0; i < V; i++)
  {
    int res = dfs(i);
    if (res == -1)
    {
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans, res);
  }
  cout << ans << endl;
}