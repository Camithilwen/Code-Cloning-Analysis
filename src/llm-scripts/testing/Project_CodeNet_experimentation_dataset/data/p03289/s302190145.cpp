// ABC_104_B
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;

  bool flag1 = false, flag2 = false, flag3 = false;

  if (s[0] == 'A') flag1 = true;

  int counter_1 = 0;
  for (int i = 2; i < s.size()-1; ++i) {
    if (s[i] == 'C') ++counter_1;
    else continue;
  }

  if (counter_1 == 1) flag2 = true;
  
  int counter_2 = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (isupper(s[i])) ++counter_2;
    else continue;
  }

  if (counter_2 == 2) flag3 = true;

  if (flag1 && flag2 && flag3) cout << "AC" << "\n";
  else cout << "WA" << "\n";

  return 0;
}
