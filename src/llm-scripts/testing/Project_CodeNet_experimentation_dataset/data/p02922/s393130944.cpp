#include <bits/stdc++.h>
using namespace std;

int main() {
  int a = 0,b = 0;
  cin >> a >> b;
  a--;
  b--;
  cout << (b + (a - 1)) / a << endl;
  return 0;
}