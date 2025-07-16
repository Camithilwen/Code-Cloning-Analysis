#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{
  string s[3];
  for (int i = 0; i < 3; i++)
    cin >> s[i];

  int count = 0;

  for (;;)
  {
    char tmp = s[count][0];
    //cout << tmp << " " << s[count] << endl;

    if (s[count].size() == 0)
      break;
    if (tmp == 'a')
    {
      s[count].erase(0, 1);
      count = 0;
    }
    else if (tmp == 'b')
    {
      s[count].erase(0, 1);
      count = 1;
    }
    else if (tmp == 'c')
    {
      s[count].erase(0, 1);
      count = 2;
    }
  }
  char ans;
  for (int i = 0; i < 3; i++)
  {
    if (count == i)
    {
      ans = 'A' + i;
      cout << ans << endl;
      break;
    }
  }
}
