#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int a;
  cin >> a;
  int vmax = a;
  int g = a;
  for (int i = 1; i < n; ++i) {
    cin >> a;
    g = __gcd(g, a);
    vmax = max(a, vmax);
  }
  cout << (k / g * g == k && k <= vmax ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}