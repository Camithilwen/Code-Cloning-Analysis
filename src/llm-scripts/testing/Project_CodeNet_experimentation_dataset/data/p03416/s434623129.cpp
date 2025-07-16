#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int ans = 0;
  for ( int n = a; n <= b; n++ ) {
    string num = to_string(n);
    if ( num[0] == num[4] && num[1] == num[3] ) { ans++; }
  }

  cout << ans << endl;
  return 0;
}
