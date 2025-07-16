#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    cin >> a >> b >> c >> d;
  }
  sum += (a < b) ? a : b;
  sum += (c < d) ? c : d;
  cout << sum << endl;
  return 0;
}