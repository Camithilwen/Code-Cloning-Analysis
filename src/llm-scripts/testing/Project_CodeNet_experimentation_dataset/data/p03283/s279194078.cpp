#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

int dp[505][505];
void solve()
{
  int n, m, q, l, r, ql, qr;
  cin >> n >> m >> q;
  for(int i = 0; i < m; ++i)
  {
    cin >> l >> r;
    dp[l][r]++;
  }


  for(int y = 1; y <= n; ++y)
  {
    for(int x = 1; x <= n; ++x)
    {
      dp[y][x] += dp[y][x - 1];
    }    
  }

  for(int x = 1; x <= n; ++x)
  {
    for(int y = 1; y <= n; ++y)
    {
      dp[y][x] += dp[y - 1][x];
    }    
  }

  for(int i = 0; i < q; ++i)
  {
    cin >> ql >> qr;
    ql--;
    cout << dp[qr][qr] - dp[ql][qr] - dp[qr][ql] + dp[ql][ql] << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}