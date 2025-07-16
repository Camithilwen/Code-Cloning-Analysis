#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <iomanip>
#include <complex>
#define rep(i, j, n) for (int i = (j); i < (n); ++i)
#define rrep(i, j, n) for (int i = (n)-1; i >= (j); --i)
using namespace std;
using ll = long long;
constexpr ll INF = 1LL << 60;

int n, m, a, b;
vector<int> g[1010];

int main()
{
  int n, m;
  cin >> n >> m;
  rep(i, 0, m)
  {
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
  }

  ll ans = INF;
  vector<int> out;

  rep(i, 0, n)
  {
    // i スタートの最小のサイクル
    vector<int> prev(n, -1);
    vector<bool> seen(n, false);
    queue<int> q;
    bool cycle = false;
    q.push(i);
    while (q.size())
    {
      int v = q.front();
      q.pop();
      for (int nv : g[v])
      {
        if (nv == i)
        {
          prev[i] = v;
          cycle = true;
          break;
        }
        if (!seen[nv])
        {
          seen[nv] = true;
          prev[nv] = v;
          q.push(nv);
        }
      }
      if (cycle)
        break;
    }

    if (cycle)
    {
      int j = i;
      vector<int> tmp;
      while (prev[j] != i)
      {
        tmp.push_back(j);
        j = prev[j];
      }
      tmp.push_back(j);

      if ((int)tmp.size() < ans)
      {
        ans = (int)tmp.size();
        out = tmp;
      }
    }
  }

  if (ans == INF)
    cout << -1 << endl;
  else
  {
    cout << out.size() << '\n';
    for (int o : out)
      cout << o + 1 << '\n';
  }
  return 0;
}
