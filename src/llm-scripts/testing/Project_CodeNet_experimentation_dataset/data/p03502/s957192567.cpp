#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a, x, y;
  cin >> a;
  x = a;

  // ここにプログラムを追記
  while (x > 0) {
    y += x % 10;
    x /= 10;
  }
  if ((a % y) == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
