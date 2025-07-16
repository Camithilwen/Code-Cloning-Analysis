#include <iostream>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0; i<(int)(n); i++)

signed main() {
  int a, b;
  cin >> a >> b;
  
  int s = 0, n = (int)1e6;
  rep(i0,n) {
    int i = i0 + 2, fa = 0, fb = 0;
    while(a % i == 0) a /= i, fa = 1;
    while(b % i == 0) b /= i, fb = 1;
    s += (fa && fb);
  }
  
  cout << s + 1 + (a != 1 && a == b) << endl;
  return 0;
}