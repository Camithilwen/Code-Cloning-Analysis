#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t x, y; cin >> x >> y;
  
  if (0 < x && 0 < y) {
    if (x < y) cout << y - x << endl;
    else cout << abs(y - x) + 2 << endl;
  }
  
  if (x == 0) {
    if (x < y) cout << y << endl;
    else cout << abs(y) + 1 << endl;
  }
  
  if (y == 0) {
    if (x < y) cout << abs(x) << endl;
    else cout << x + 1 << endl;
  }
  
  if (x < 0 && y < 0) {
    if (x < y) cout << y - x << endl;
    else cout << abs(y) - abs(x) + 2 << endl;
  }
  
  if (x < 0 && 0 < y) {
    cout << min(abs(x) + abs(y), abs(abs(y) - abs(x)) + 1) << endl;
  }
  
  if (y < 0 && 0 < x) {
    cout << abs(abs(y) - abs(x)) + 1 << endl;
  }
  
}