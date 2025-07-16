#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b, c, k;
  cin >> a >> b >> c >> k;
  
  long long ans = a + b + c;
  a = max(a, max(b, c));
  ans -= a;
  for(int i = 0; i < k; i++) a *= 2;
  
  cout << ans + a << endl;
}