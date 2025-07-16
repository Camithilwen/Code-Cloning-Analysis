#include <iostream>
#include <iomanip>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n, k;
  cin >> n >> k;
  int p[n];
  rep(i,n) cin >> p[i], p[i]++;
  
  int s = 0, m = 0;
  rep(i,n) {
    s = s + p[i] - (i >= k ? p[i-k] : 0);
    m = max(m, s);
  }
  
  cout << fixed << setprecision(1) << (double)m / 2 << endl;
  return 0;
}