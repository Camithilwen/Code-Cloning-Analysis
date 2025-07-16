#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x, y;
  cin >> x >> y;
  --x, --y;

  int c[] = { 300000, 200000, 100000, 0 };
  cout << c[min(x, 3)] + c[min(y, 3)] + (!x && !y ? 400000 : 0) << endl;

  return (0);
}
