#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
const string MININF = "-INF";
int match[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string dp[MAXN]; // i本のマッチ棒を使ったときの最大数

void chmax(string &a, string b)
{
  if (a == MININF)
  {
    a = b;
  }
  else if (a.size() < b.size())
  {
    a = b;
  }
  else if (a.size() == b.size())
  {
    if (a < b)
    {
      a = b;
    }
  }
}

int main()
{
  int N, M, a;
  cin >> N >> M;
  vector<int> A(M);
  for (int i = 0; i < M; i++)
  {
    cin >> A.at(i);
  }
  for (int i = 0; i < MAXN; i++)
  {
    dp[i] = MININF;
  }
  dp[0] = "";
  for (int i = 0; i <= N; i++)
  {
    if (dp[i] == MININF)
      continue;
    for (int a : A)
    {
      chmax(dp[i + match[a]], dp[i] + (char)(a + '0'));
    }
  }
  cout << dp[N] << endl;
}
