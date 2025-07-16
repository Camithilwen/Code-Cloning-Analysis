#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
  string s;
  cin>>s;
  int c = 0;
  for (char c1 : s) if (c1 == 'R') c++;
  if (c != 2) cout << c << '\n';
  else if (s[1] == 'S') cout << 1 << '\n';
  else cout << '2' << '\n';
  return 0;
}