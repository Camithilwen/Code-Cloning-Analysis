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
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  int mx = -1000, mn = 1000;
  rep(i, n){
    int in;
    cin >> in;
    mx = max(mx, in);
  }
  rep(i, m){
    int in;
    cin >> in;
    mn = min(mn, in);
  }
  bool f = false;
  if(mx >= mn) f = true;
  if(mn <= x || y < mn) f = true;
  if(f == false) cout << "No ";
  cout << "War" << endl;

  return 0;
}