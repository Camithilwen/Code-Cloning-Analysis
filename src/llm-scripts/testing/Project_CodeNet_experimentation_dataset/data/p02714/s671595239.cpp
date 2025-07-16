#include <iostream>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0; i<(int)(n); i++)

signed main() {
  int n;
  cin >> n;
  int s[n];
  rep(i,n) {
    char c;
    cin >> c;
    if(c == 'R') s[i] = 0;
    if(c == 'G') s[i] = 1;
    if(c == 'B') s[i] = 2;
  }
 
  int r[3][n+1];
  rep(i,3) rep(j,n+1) r[i][j] = 0;
  rep(i,3) rep(j,n) if(i == s[j]) r[i][j]++;
  rep(i,3) rep(j,n) r[i][n-1-j] = r[i][n-1-j] + r[i][n-j];
 
  int w = 0;
  rep(i,n) rep(j0,n-i-1) {
    int j = j0 + i + 1;
    if(s[i] != s[j]) {
      int k = 3 - s[i] - s[j], l = 2 * j - i;
      w += r[k][j+1];
      if(l < n && k == s[l]) w -= 1;
    }
  }
  cout << w << endl;
  return 0;
}