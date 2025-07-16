#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n;
  cin >> n;
  vector<queue<int>> a(n);
  rep(i, n)
    rep(j, n - 1)
    {
      int ipt;
      cin >> ipt;
      ipt--;
      a[i].push(ipt);
    }
  set<pair<int, int>> s;
  rep(i, n - 1)
  {
    int op = a[i].front();
    if (i == a[op].front() && i < op)
      s.emplace(i, op);
  }
  int ans = 0;
  while (!s.empty())
  {
    ans++;
    set<pair<int, int>> s2;
    while (!s.empty())
    {
      auto p = *s.begin();
      s.erase(s.begin());
      a[p.first].pop();
      a[p.second].pop();
      if (!a[p.first].empty())
      {
        int op = a[p.first].front();
        if (!a[op].empty() && p.first == a[op].front())
          s2.emplace(min(p.first, op), max(p.first, op));
      }
      if (!a[p.second].empty())
      {
        int op = a[p.second].front();
        if (!a[op].empty() && p.second == a[op].front())
          s2.emplace(min(p.second, op), max(p.second, op));
      }
    }
    s.swap(s2);
  }
  rep(i, n)
    if (!a[i].empty())
    {
      puts("-1");
      return 0;
    }
  cout << ans << endl;
  return 0;
}