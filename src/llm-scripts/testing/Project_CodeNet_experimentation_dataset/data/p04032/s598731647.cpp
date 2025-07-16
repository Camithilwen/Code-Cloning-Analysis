#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  if (s.length() == 2)
  {
    if (s[0] == s[1])
    {
      cout << 1 << " " << 2 << endl;
      return 0;
    }
  }
  for (int i = 0; i < s.length() - 2; i++)
  {
    if (s[i] == s[i + 2])
    {
      cout << i + 1 << " " << i + 3 << endl;
      return 0;
    }
    else if (s[i] == s[i + 1])
    {
      cout << i + 1 << " " << i + 2 << endl;
      return 0;
    }
    else if (s[i + 1] == s[i + 2])
    {
      cout << i + 2 << " " << i + 3 << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << endl;
}