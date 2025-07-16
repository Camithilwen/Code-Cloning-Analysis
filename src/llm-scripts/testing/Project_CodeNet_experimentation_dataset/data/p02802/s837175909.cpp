#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> ac(n), wa(n);

  for (int i = 0; i < m; i++)
  {
    int p;
    string s;
    cin >> p >> s;

    if (ac[p - 1])
    {
      continue;
    }

    if (s == "WA")
    {
      wa[p - 1]++;
    }
    else
    {
      ac[p - 1] = 1;
    }
  }
  int AC = 0;
  int WA = 0;
  for (int i = 0; i < n; i++)
  {
    AC += ac[i];
    if (ac[i])
    {
      WA += wa[i];
    }
  }
  cout << AC << " " << WA << endl;
}
