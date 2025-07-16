#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n, m;
  cin >> n >> m;
  int l = (m+1)/2, r = m/2;
  rep(i,l) cout << i+1 << " " << 2*l - i << endl;
  rep(i,r) cout << 2*l + i+1 << " " << 2*(l+r) - i + 1 << endl;
  return 0;
}