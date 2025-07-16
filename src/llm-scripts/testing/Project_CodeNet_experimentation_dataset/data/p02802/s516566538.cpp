#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> ac(n, 0);
  vector<int> wa(n, 0);
  rep(i, m)
  {
    int p;
    string s;
    cin >> p >> s;
    p--;
    if (ac[p] == 1)
      continue;
    if (s == "AC")
      ac[p] = 1;
    else
      wa[p]++;
  }
  rep(i, n)
    wa[i] *= ac[i];
  cout << accumulate(ac.begin(), ac.end(), 0) << ' ' << accumulate(wa.begin(), wa.end(), 0) << endl;
  return 0;
}