#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int cnt = 1;
  while (1) {
    if ((a-1) * (cnt-1) + a >= b) break;
    cnt++;
  }
  if (b == 1) cout << 0 << endl;
  else cout << cnt << endl;
  return 0;
}
