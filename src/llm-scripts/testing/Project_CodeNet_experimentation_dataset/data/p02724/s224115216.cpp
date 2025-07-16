#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x;
  cin >> x;

  int ans = 0;
  ans += x / 500 * 1000;
  x %= 500;
  ans += x / 5 * 5;

  cout << ans << endl;
  return 0;
}