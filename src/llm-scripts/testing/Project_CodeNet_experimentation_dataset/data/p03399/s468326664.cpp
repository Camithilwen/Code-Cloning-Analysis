#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int a , b, c, d;
  cin >> a >> b >> c >> d;
  int s = min(a,b);
  int t = min(c,d);
  cout << s+t << endl;
  return 0;
}