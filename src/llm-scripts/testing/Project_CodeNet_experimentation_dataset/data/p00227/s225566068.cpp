#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int n, m, cost;
  int p[1000];
  while (true) {
    cin >> n >> m;
    if (n == 0) {
      return 0;
    }
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    sort(p, p + n);
    cost = accumulate(p, p + n, 0);
    for (int i = n - m; i >= 0; i -= m) {
      cost -= p[i];
    }
    cout << cost << endl;
  }
}