#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y;
  cin >> x;
  y = x % 500;
  x /= 500;
  y /= 5;
  cout << 1000*x+5*y << endl;
  return 0;
}
