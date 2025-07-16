#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(), v.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main()
{
  int H, W,inf=100000000,ans=0;
  cin>>H>>W;
  vvc field(H, vc(W));
  vvi d(H, vi(W, inf));
  queue<PAIR> que;
  rep(i,H)
  {
    rep(j,W)
    {
      cin >> field[i][j];
      if (field[i][j]=='#')
      {
        que.push(PAIR(i, j));
        d[i][j] = 0;
      }
    }
  }

  while(que.size())
  {
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    PAIR p = que.front();
    que.pop();

    rep(i, 4)
    {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(0<=nx&&nx<H&&0<=ny&&ny<W&&field[nx][ny]=='.'&&d[nx][ny]==inf)
        {
          d[nx][ny] = d[p.first][p.second] + 1;
          que.push(PAIR(nx, ny));
          ans = max(ans, d[nx][ny]);
        }
    }
  }
  cout << ans << endl;
}
