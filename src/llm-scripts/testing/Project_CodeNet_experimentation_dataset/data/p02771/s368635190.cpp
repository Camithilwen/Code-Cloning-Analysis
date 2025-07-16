#include <bits/stdc++.h>
using namespace std;

bool f(int a, int b, int c) {
  return ( a == b && a != c ?
          true : false);
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << (f(a, b, c) || f(c, a, b) || f(b, c, a) ?
    "Yes" : "No");
}
