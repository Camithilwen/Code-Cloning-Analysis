#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int sx, sy;
  cin >> sx >> sy;
  int tx, ty;
  cin >> tx >> ty;
  int dx = tx - sx, dy = ty - sy;
  cout << string(dy, 'U');
  cout << string(dx, 'R');
  cout << string(dy, 'D');
  cout << string(dx, 'L');
  cout << 'L';
  cout << string(dy+1, 'U');
  cout << string(dx+1, 'R');
  cout << "DR";
  cout << string(dy+1, 'D');
  cout << string(dx+1, 'L');
  cout << "U" << endl;
  return 0;
}