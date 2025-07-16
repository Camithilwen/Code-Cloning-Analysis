#include <bits/stdc++.h>
using namespace std;

signed main()
{
  double x1, x2, y1, y2;

  cin >> x1 >> y1 >> x2 >> y2;
  cout << fixed << setprecision(10) << sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) << endl;

  return (0);
}