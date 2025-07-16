#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int h, w;
  cin >> h >> w;
  vector< vector<int> > a( h, vector<int>(w) );
  for(int i = 0; i < h; ++i)
  {
    for(int j = 0; j < w; ++j)
    {
      cin >> a[i][j];
    }
  }

  vector<tuple<int, int, int, int>> ans;
  for(int i = 0; i < h; ++i)
  {
    for(int j = 0; j < w; ++j)
    {
      if(a[i][j] & 1)
      {
        if (j < w - 1)
        {
          a[i][j + 1]++;
          ans.emplace_back(make_tuple(i, j, i, j + 1));
        }
        else if (i < h - 1)
        {
          a[i + 1][j]++;
          ans.emplace_back(make_tuple(i, j, i + 1, j));
        }
      }
    }
  }

  cout << ans.size() << endl;
  for(const auto& t : ans)
  {
    int x, y, ax, ay;
    tie(x, y, ax, ay) = t;
    cout << x + 1 << " " << y + 1 << " " << ax + 1 << " " << ay + 1 << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}