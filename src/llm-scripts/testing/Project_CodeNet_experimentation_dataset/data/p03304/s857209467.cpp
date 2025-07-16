#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  double n, m, d;
  cin >> n >> m >> d;
  double ans;
  if(d == 0){
    ans = 1/n;
  }else{
    ans = 2*(n-d)/(n*n);
  }
  ans *= (m-1);
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}