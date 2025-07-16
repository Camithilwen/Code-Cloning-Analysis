#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int64_t al[MAXN][26];

int main()
{
  string S;
  cin >> S;
  for (int i = 1; i < S.size(); i++)
  {
    if (S[i - 1] == S[i])
    {
      cout << i << ' ' << i + 1 << endl;
      return 0;
    }
    if (i != 1 && S[i - 2] == S[i])
    {
      cout << i - 1 << ' ' << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << ' ' << -1 << endl;
}