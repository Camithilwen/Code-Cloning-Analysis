#include <bits/stdc++.h>
using namespace std;

int a, b, k;

int main() {
  cin >> a >> b >> k;
  for (int i = 0; i < k; ++i) {
    a /= 2;
    b += a;
    swap(a, b);
  }
  if (k & 1) swap(a, b);
  cout << a << " " << b << endl;
  return 0;
}
