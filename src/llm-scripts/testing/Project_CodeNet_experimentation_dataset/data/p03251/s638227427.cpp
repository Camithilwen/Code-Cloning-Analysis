#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  int xmax = x;
  int ymin = y;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a;
    xmax = max(a, xmax);
  }
  for (int i = 0; i < m; i++) {
    cin >> b;
    ymin = min(b, ymin);
  }
  if (xmax < ymin) {
    cout << "No War" << endl;
  }
  else {
    cout << "War" << endl;
  }
}
