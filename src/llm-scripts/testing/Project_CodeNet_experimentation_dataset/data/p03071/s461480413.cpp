#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  int ans;
  if (a == b) {
    ans = a + b;
  } else {
    int mx = max(a, b);
    ans = mx + mx - 1;
  }

  cout << ans << endl;
  return 0;
}
