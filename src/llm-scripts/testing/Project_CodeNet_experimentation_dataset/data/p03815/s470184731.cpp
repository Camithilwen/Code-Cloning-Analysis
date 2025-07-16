#include <bits/stdc++.h>
using namespace std;

long long int MOD = 1000000007;

int main() {
  long long int X;
  cin >> X;
  if (X % 11 == 0) cout << X / 11 * 2 << endl;
  else if (X % 11 <= 6) cout << X / 11 * 2 + 1 << endl;
  else cout << X / 11 * 2 + 2 << endl;
}