#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string s;
  int cnt = 0;
  cin >> s;

  if (s[0] != 'A')
  {
    cout << "WA" << endl;
    return 0;
  }

  for (int i = 1; i < s.length(); i++)
  {
    if (i > 1 && i < s.length() - 1)
    {
      if (s[i] == 'C')
      {
        if (cnt == 0)
        {
          cnt = 1;
          continue;
        }
        else
        {
          cout << "WA" << endl;
          return 0;
        }
      }
    }
    if (s[i] - '0' >= 17 && s[i] - '0' <= 42)
    {
      cout << "WA" << endl;
      return 0;
    }
  }
  if (cnt == 0)
  {
    cout << "WA" << endl;
    return 0;
  }

  cout << "AC" << endl;
}