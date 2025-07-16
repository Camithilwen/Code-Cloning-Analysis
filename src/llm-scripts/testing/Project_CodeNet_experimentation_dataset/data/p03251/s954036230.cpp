#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> xv(n);
  vector<int> yv(m);
  int xmax = x;
  int ymin = y;
  rep(i, n) {
    cin >> xv[i];
    xmax = max(xmax, xv[i]);
  }
  rep(i, m) {
    cin >> yv[i];
    ymin = min(ymin, yv[i]);
  }
  
  if(xmax < ymin) cout << "No War" << endl;
  else cout << "War" << endl;
  return 0;
}
    