#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, m, ans = 0;
  cin >> n;
  map<string, int> s;
  map<string, int> t;
  for (int i = 0; i < n; i++)
  {
    string blue;
    cin >> blue;
    s[blue]++;
  }
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    string red;
    cin >> red;
    t[red]++;
  }

  for (auto i = s.begin(); i != s.end(); i++)
  {
    ans = max(ans, i->second - t[i->first]);
  }
  cout << ans << endl;
}
