/*input
8 3
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  int l = 1, r = n;
  for (int i = 1; i <= m; ++i) {
    if (n%2 == 0 && i == n/2/2+1) l++;
    cout << l << " " << r << endl;
    l++; r--;
  }
  return 0;
}