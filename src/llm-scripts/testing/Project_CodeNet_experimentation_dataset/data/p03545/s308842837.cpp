#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  string s;
  cin >> s;
  int a = (s[0] - '0');
  int b = (s[1] - '0');
  int c = (s[2] - '0');
  int d = (s[3] - '0');
  for(int op1 = -1; op1 <= 1; op1 += 2)
  for(int op2 = -1; op2 <= 1; op2 += 2)
  for(int op3 = -1; op3 <= 1; op3 += 2)
  {
    if (a + b * op1 + c * op2 + d * op3 == 7)
    {
      cout << a;
      cout << (op1 == -1 ? '-' : '+');
      cout << b;
      cout << (op2 == -1 ? '-' : '+');
      cout << c;
      cout << (op3 == -1 ? '-' : '+');
      cout << d;
      cout << "=7";
      return;
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}