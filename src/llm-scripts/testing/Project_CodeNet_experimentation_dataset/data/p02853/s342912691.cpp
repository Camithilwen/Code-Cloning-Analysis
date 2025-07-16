#include <iostream>

using namespace std;

int main () {
  int x, y;
  cin >> x >> y;

  int ans = 0;
  ans += max(4 - x, 0);
  ans += max(4 - y, 0);
  if (x == 1 && y == 1) ans += 4;
  ans *= 100000;

  cout << ans << endl;
}
