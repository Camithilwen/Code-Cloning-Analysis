#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, r; cin >> n >> r;
  n = min(n, 10);
  cout << r + 100 * (10-n) << endl;
  return 0;
}